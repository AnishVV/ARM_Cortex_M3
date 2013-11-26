; LCD.s
; Runs on LM3S1968
; EE319K lab 6 device driver for the LCD
; Valvano
; March 2, 2013 (Spring 2013 version)
;
;  size is 1*16
;  because we do not need to read busy, then we will tie R/W=ground
;  10k potentiometer (not the slide pot for Lab 8)
;      one end of pot is +5V, 
;      center of pot to pin 3 of LCD,
;      other end of pot is ground
;  ground = pin 1    Vss
;  power  = pin 2    Vdd   +5V (EE319K LCDs)
;  pot    = pin 3    Vlc   connected to center of pot
;  PF4    = pin 4    RS    (1 for data, 0 for control/status)
;  ground = pin 5    R/W   (1 for read, 0 for write)
;  PF5    = pin 6    E     (enable)
;  PF0    = pin 11   DB4   (4-bit data)
;  PF1    = pin 12   DB5
;  PF2    = pin 13   DB6
;  PF3    = pin 14   DB7
;16 characters are configured as 2 rows of 8
;addr  00 01 02 03 04 05 06 07 40 41 42 43 44 45 46 47


        EXPORT   LCD_Open
        EXPORT   LCD_Clear
        EXPORT   LCD_OutChar
        EXPORT   LCD_GoTo
        EXPORT   LCD_OutString
        EXPORT   LCD_OutChar
        EXPORT   LCD_OutDec
        EXPORT   LCD_OutFix
SYSCTL_RCGC2_R          EQU 0x400FE108
SYSCTL_RCGC2_GPIOF      EQU 0x00000020   ; port F Clock Gating Control

E						EQU 0x40025080
RS						EQU 0x40025040
DATA					EQU GPIO_PORTF_DATA_R + 60
GPIO_PORTF_DATA_R		EQU 0x40025000
GPIO_PORTF_DIR_R        EQU 0x40025400
GPIO_PORTF_AFSEL_R      EQU 0x40025420
GPIO_PORTF_DEN_R        EQU 0x4002551C

      AREA    |.text|, CODE, READONLY, ALIGN=2
      THUMB
      ALIGN          


;--------------- outCsrNibble ------------------
; Sends 4 bits to the LCD control/status
; Input: R0 is 4-bit command, in bit positions 3,2,1,0 of R0
; Output: none
; This is a private function
; Invariables: This function must not permanently modify registers R4 to R11
outCsrNibble
      PUSH {LR}
	  PUSH {R1-R12}
	  ;set E and RS to 0
	  LDR R1, =RS
	  MOV R2, #0
	  STRB R2, [R1]
	  LDR R1, =E
	  STR R2, [R1]
	  
	  ;Send data
	  LDR R3, =DATA
	  STRB R0, [R3]
	  ;delay 6 us
	  BL Delay_6us
	  ;set E to 1
	  MOV R6, #0x20
	  STRB R6, [R1]
	  ;delay 6 Us
	  BL Delay_6us
	  ;set E to 0
	  STRB R2, [R1]
	  ;delay 6 ns
	  BL Delay_6us
	  
	  POP {R1-R12}
      POP {PC}

;-----------Delay_6 us-----------------
;Delay function spends 6 us doing "nothing"
;Input: None
;Output: spends 6 us of time
;Modifies: R0
Delay_6us	PUSH {R0}
			MOV R0,#75
wait4		SUBS R0,R0,#0x01
			BNE wait4
			POP{R0}
			BX LR

;---------------------outCsr---------------------
; Sends one command code to the LCD control/status
; Input: R0 is 8-bit command to execute
; Output: none
;* Entry Mode Set 0,0,0,0,0,1,I/D,S
;*     I/D=1 for increment cursor move direction
;*        =0 for decrement cursor move direction
;*     S  =1 for display shift
;*        =0 for no display shift
;*   Display On/Off Control 0,0,0,0,1,D,C,B
;*     D  =1 for display on
;*        =0 for display off
;*     C  =1 for cursor on
;*        =0 for cursor off
;*     B  =1 for blink of cursor position character
;*        =0 for no blink
;*   Cursor/Display Shift  0,0,0,1,S/C,R/L,*,*
;*     S/C=1 for display shift
;*        =0 for cursor movement
;*     R/L=1 for shift to left
;*        =0 for shift to right
;*   Function Set   0,0,1,DL,N,F,*,*
;*     DL=1 for 8 bit
;*       =0 for 4 bit
;*     N =1 for 2 lines
;*       =0 for 1 line
;*     F =1 for 5 by 10 dots
;*       =0 for 5 by 7 dots 
; This is a private function
; Invariables: This function must not permanently modify registers R4 to R11
outCsr
			PUSH {LR}
			PUSH {R1-R12}
			MOV R5, R0				;R5 = input
			LSR R0, #4	;isolate most sig nibble
			;outCsrNibble(MS_nibble)
			BL outCsrNibble
			MOV R0, R5				;reset r0 to input
			BIC R0, #0xF0			;isolate least sig nibble
			;outCsrNibble(LS_nibble)
			BL outCsrNibble
			;delay
			BL Delay_90uS
			POP  {R1-R12}
			POP  {PC}

;---------------------LCD_Open---------------------
; initialize the LCD display, called once at beginning
; Input: none
; Output: none
; This is a public function
; Invariables: This function must not permanently modify registers R4 to R11
LCD_Open 
			PUSH {LR}
			PUSH {R0-R12}
			;delay 30 ms
			MOV R3, #20
			BL Delay_TIME
			;initialize Port F
			BL PortF_Init
			;outCsrNibble(0x003)
			MOV R0, #0x03
			BL outCsrNibble
			;delay 5 ms
			MOV R3, #5
			BL Delay_TIME
			;outCsrNibble(0x003)
			MOV R0, #0x03
			BL outCsrNibble
			BL Delay_100uS
			;outCsrNibble(0x003)
			MOV R0, #0x03
			BL outCsrNibble
			BL Delay_100uS
			;outCsrNibble(0x002)
			MOV R0, #0x02
			BL outCsrNibble
			BL Delay_100uS
			
			;outCsr(0x28)
			MOV R0, #0x28
			BL outCsr
			;outCsr(0x14)
			MOV R0, #0x14
			BL outCsr
			;outCsr(0x06)
			MOV R0, #0x06
			BL outCsr
			;outCsr(0x0C)
			MOV R0, #0x0C
			BL outCsr
			
			;BL LCD_Clear
			POP {R0-R12}
			POP {PC}



;-----------Delay_90uS-----------------
;Delay function spends 90 us doing "nothing"
;Input: None
;Output: spends 90 us of time
;Modifies: R0
Delay_90uS	PUSH {R0}
			MOV R0,#1127
wait3		SUBS R0,R0,#0x01
			BNE wait3
			POP {R0}
			BX LR
			
		

;-----------Delay_100uS-----------------
;Delay function spends 100 us doing "nothing"
;Input: None
;Output: spends 100 us of time
;Modifies: R0
Delay_100uS	MOV R0,#1250
wait2		SUBS R0,R0,#0x01
			BNE wait2
			BX LR



;-----------Delay-----------------
;Delay function spends 1ms doing "nothing"
;Input: None
;Output: spends 1ms of time
;Modifies: R0
Delay	MOV R0,#12500
wait	SUBS R0,R0,#0x01
		BNE wait
		BX LR
		
		

;------------Delay_TIME------------
;DelaY function spends Time in ms dettermined by R0 using busy delay (assumes 50Mhz)
;Input: R3(R3 contains wait time)
;Output: None
;Modifies: R0, R1, R2
Delay_TIME	PUSH {R0-R2}
			MOV R1,R3
			;ADD R2, LR, #0
			PUSH {LR}
loop_d		BL Delay
			SUBS R1,R1,#0x01
			BNE loop_d
			;ADD LR, R2, #0
			POP {LR}
			POP {R0-R2}
			BX LR
			
			

;---------------------LCD_OutChar---------------------
; sends one ASCII to the LCD display
; Input: R0 (call by value) letter is 8-bit ASCII code
; Outputs: none
; This is a public function
; Invariables: This function must not permanently modify registers R4 to R11
LCD_OutChar
		PUSH {LR}
		PUSH {R1-R12}
		;set E and RS to 0
		LDR R1, =RS
		MOV R2, #0x10
		STRB R2, [R1]
		LDR R1, =E
		MOV R3, #0
		STRB R3, [R1]
		
		;OUT 4 most sig bits
		LDR R3, =DATA
		MOV R1, R0
		LSR R1, #4
		STRB R1, [R3]
		;delay 6 us
		BL Delay_6us
		;Enable E to 1
		LDR R1, =E
		MOV R6, #0x20
		STRB R6, [R1]
		;delay 6 us
		BL Delay_6us
		LDR R1, =E
		MOV R3, #0
		STRB R3, [R1]
		;delay 6 us
		BL Delay_6us
		
		;OUT 4 least sig bits
		LDR R3, =DATA
		MOV R1, R0
		BIC R1, #0xF0
		STRB R1, [R3]
		;delay 6 us
		BL Delay_6us
		;Enable E to 1
		LDR R1, =E
		MOV R6, #0x20
		STRB R6, [R1]
		;delay 6 us
		BL Delay_6us
		LDR R1, =E
		MOV R3, #0
		STRB R3, [R1]
		;delay 6 us
		BL Delay_6us
		
		;wait 90 us
		BL Delay_90uS
		POP {R1-R12}
		POP {PC}

;---------------------LCD_Clear---------------------
; clear the LCD display, send cursor to home
; Input: none
; Outputs: none
; This is a public function
; Invariables: This function must not permanently modify registers R4 to R11
LCD_Clear
		PUSH {LR}         
		PUSH {R0}
		
		;outCsr(0x01)
		MOV R0, #0x01
		BL outCsr
		
		;WAIT 1.64 MS
		BL Delay
		BL Delay_640uS
		
		;outCsr(0x02)
		MOV R0, #0x02
		BL outCsr
		
		;WAIT 1.64 MS
		BL Delay
		BL Delay_640uS
		
		POP {R0}
		POP  {PC}


;-----------Delay_640uS-----------------
;Delay function spends 640 us doing "nothing"
;Input: None
;Output: spends 640 us of time
;Modifies: R0
Delay_640uS	MOV R0,#8000
wait5		SUBS R0,R0,#0x01
			BNE wait5
			BX LR

;-----------------------LCD_GoTo-----------------------
; Move cursor (set display address) 
; Input: R0 is display address (DDaddr) is 0 to 7, or 0x40 to 0x47 
; Output: none
; errors: it will check for legal address
;  0) save any registers that will be destroyed by pushing on the stack
;  1) go to step 3 if DDaddr is 0x08 to 0x3F or 0x48 to 0xFFFFFFFF
;  2) outCsr(DDaddr+0x80)     
;  3) restore the registers by pulling off the stack
; This is a public function
; Invariables: This function must not permanently modify registers R4 to R11
LCD_GoTo
			PUSH {LR}  
			PUSH {R1-R12}
			
			MOV R1,#0x07
            CMP R0,R1
            BLS YES
			MOV R1,#0x47
			CMP R0,R1
			BHI EXIT
			MOV R1,#0x3F
			CMP R0,R1
			BLS EXIT

YES			ADD R0, R0, #0X80
			BL outCsr
			
EXIT		POP {R1-R12}
			POP  {PC}

; ---------------------LCD_OutString-------------
; Output character string to LCD display, terminated by a NULL(0)
; Inputs:  R0 (call by reference) points to a string of ASCII characters 
; Outputs: none
; This is a public function
; Invariables: This function must not permanently modify registers R4 to R11
LCD_OutString
			PUSH {LR}   
			PUSH {R6}
			MOV R6, R0
LOOPO		LDR R0, [R6]
			ADD R6, R6, #1
			ADDS R0, R0, #0
			BEQ ENDO
			BL LCD_OutChar
			B LOOPO
ENDO		POP {R6}
			POP {PC}



;-----------------------LCD_OutDec-----------------------
; Output a 32-bit number in unsigned decimal format
; Input: R0 (call by value) 32-bit unsigned number 
; Output: none
; This is a public function
; Invariables: This function must not permanently modify registers R4 to R11
LCD_OutDec
			                ;-------Binding phase---------

N                                                                                             EQU 0

                ;-------Allocation phase-------

                                PUSH {R0,R3,R4,R5,R6,R11,LR}                  

                                SUB SP,#4                                                                           ;Allocate 4 memory locations for the variable n

                ;------Access phase---------

                                MOV R11,SP                                                                       ;R11 holds the pointer to the variable n

                                STR R0,[R11,#N]                                                               ;Store the variable n at offset of 0

                                MOV R5,#10                                                                       ;R5 holds ten, the constant divisor

                                MOV R4,#0                                                                         ;R4 will count the number of digits put on stack

loop       LDR R3,[R11]                                                      ;Load n into R3

                                CMP R3,R5                                                                          ;See if n<10

                                BLT out

                                UDIV R6,R3,R5                                                   ;Takes the quotient of n/10 and puts it in R6

                                MLS R0,R5,R6,R3                                                              ;Takes the remainder of n/10 and puts it in R0

                                STR R6,[R11,#N]                                                               ;Store the new n back in memory

                                PUSH {R0}                                                                           ;Push the remainder on the stack

                                ADD R4,#1

                                B loop

out                         MOV R0,R3                                                                         ;Takes the most final quotient which is <10 to R0

                                ADD R0,#0x30

                                BL LCD_OutChar

                ;Check if R4==0 indicating no remainders pushed on stack

                                ADDS R4,#0

                                BEQ DeAl

print      POP {R0}

                                ADD R0,#0x30

                                BL LCD_OutChar

                                SUBS R4,#1

                                BNE print

                ;------Deallocation phase------

DeAl      ADD SP,#4

                                POP  {R0,R3,R4,R5,R6,R11,PC}


; -----------------------LCD _OutFix----------------------
; Output characters to LCD display in fixed-point format
; unsigned decimal, resolution 0.001, range 0.000 to 9.999 
; Inputs:  R0 is an unsigned 16-bit number
; Outputs: none
; E.g., R0=0,    then output "0.000 " 
;       R0=3,    then output "0.003 " 
;       R0=89,   then output "0.089 " 
;       R0=123,  then output "0.123 " 
;       R0=9999, then output "9.999 " 
;       R0>9999, then output "*.*** "
; This is a public function
; Invariables: This function must not permanently modify registers R4 to R11
LCD_OutFix
letter                                     EQU 0

num                                                       EQU 4

 

                ;Allocation

        PUSH {R0-R4,LR}

                                ADD SP,#-8

                ;Access Phase

                                STR R0,[SP,#num]                            ;initialize num to input parameter

                                MOV R1,#9999

                                CMP R0,R1                                          ;See if input is valid

                                BLE more

                                LDR R0,='*'                                          ;If invalid, output "*.*** "

                                BL LCD_OutChar

                                LDR R0,='.'                          

                                BL LCD_OutChar

                                LDR R0,='*'                                         

                                BL LCD_OutChar

                                BL LCD_OutChar

                                BL LCD_OutChar

                                LDR R0,=' '

                                BL LCD_OutChar

                                B DeAlo                                                                ;uncondtional branch to the end

more     MOV R1,#1000                  ;R1 holds 1000 to divide num/1000

                                LDR R2,[SP,#num]

                                UDIV R3,R2,R1                   ;R3 holds num/1000

                                MLS R0,R1,R3,R2

                                STR R3,[SP,#letter]          ;store quotient in letter

                                STR R0,[SP,#num]            ;store remainder in num

                                ADD R3,#0x30                    ;convert the ones digit to ASCII

                                MOV R0,R3                                        

                                BL LCD_OutChar                               ;output the ones digit

                                LDR R0,='.'

                                BL LCD_OutChar                               ;Output '.'

                ;Num/100

                                MOV R1,#100

                                LDR R2,[SP,#num]

                                UDIV R3,R2,R1                   ;R3 holds num/100

                                MLS R0,R1,R3,R2

                                STR R3,[SP,#letter]          ;store quotient in letter

                                STR R0,[SP,#num]            ;store remainder in num

                                ADD R3,#0x30                    ;convert the tenths digit to ASCII

                                MOV R0,R3                                        

                                BL LCD_OutChar                               ;output the tenths digit

                ;Num/10

                                MOV R1,#10

                                LDR R2,[SP,#num]

                                UDIV R3,R2,R1                   ;R3 holds num/100

                                MLS R0,R1,R3,R2

                                STR R3,[SP,#letter]          ;store quotient in letter

                                STR R0,[SP,#num]            ;store remainder in num

                                ADD R3,#0x30                    ;convert the hundredths digit to ASCII

                                MOV R0,R3                                        

                                BL LCD_OutChar                               ;output the hundredths digit

                ;output the thousandths place

                                LDR R0,[SP,#num]

                                ADD R0,#0x30

                                BL LCD_OutChar                               ;output the thousandths place

                ;output ' ' to the LCD

                                LDR R0,=' '

                                BL LCD_OutChar              

                ;Deallocation

DeAlo    ADD SP,#8

        POP {R0-R4,PC}

; -----------------------PortF_Init----------------------
; Initiates port F
; Input: None
; Output: None
; Modifies R0, R1
PortF_Init
         PUSH {LR}
		 PUSH {R0, R1}
		 ; activates clock for port F
			LDR R1, =SYSCTL_RCGC2_R			; R1 = &SYSCTL_RCGC2_R
			LDR R0, [R1]					; R0 = [R1]
			ORR R0, R0, #SYSCTL_RCGC2_GPIOF	; R0 = R0|SYSCTL_RCGC2_GPIOF
			STR R0, [R1]
			NOP
			NOP
			; set direction register
			LDR R1, =GPIO_PORTF_DIR_R		; R1 = &GPIO_PORTF_DIR_R
			LDR R0, [R1]					; R0 = [R1]
			ORR R0, R0, #0x3F               ; R0 = R0|0x3F (make PB0-5 output)
			STR R0, [R1]					; [R1] = R0
			; regular port function
			LDR R1, =GPIO_PORTF_AFSEL_R		; R1 = &GPIO_PORTF_AFSEL_R
			LDR R0, [R1]					; R0 = [R1]
			BIC R0, R0, #0x3F				; R0 = &~0x3F (disable alt function on P0-5)
			STR R0, [R1]					; [R1] = R0
			; enable digital port
			LDR R1, =GPIO_PORTF_DEN_R		; R1 = &GPIO_PORTF_DEN_R
			LDR R0, [R1]					; R0 = [R1]
			ORR R0, R0, #0x3F				; enable P0-5
			STR R0, [R1]
			POP {R0, R1}
			POP {PC}

    ALIGN                           ; make sure the end of this section is aligned
    END                             ; end of file
    