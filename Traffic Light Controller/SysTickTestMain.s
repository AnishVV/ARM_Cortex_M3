; SysTickTestMain.s
; Phillip Lemons and Anish Vaghasia
; Runs on LM3S1968
; Lab 3 EE319K Summer 2012
; Toggle on PE1 LED if Switch on PE0 is pressed
; Uses a dump debugging tool
; Date Created: May 23, 2012 
; Last Modified: 2/26/2013 

        IMPORT   SysTick_Init
        IMPORT   SysTick_Wait
        IMPORT   SysTick_Wait10ms
        IMPORT   PLL_Init
		

GPIO_PORTG_DATA_R	EQU 0x400263FC
GPIO_PORTG_PUR_R	EQU 0x40026510
GPIO_PORTG_DIR_R   	EQU 0x40026400
GPIO_PORTG_AFSEL_R 	EQU 0x40026420
GPIO_PORTG_DEN_R   	EQU 0x4002651C
SYSCTL_RCGC2_R  	EQU 0x400FE108
SYSCTL_RCGC2_GPIOG	EQU 0x00000040   ; port G Clock Gating Control

SYSCTL_RCGC2_GPIOE 	EQU 0x00000010
GPIO_PORTE_DATA_R	EQU 0x400243FC
GPIO_PORTE_DIR_R	EQU 0x40024400
GPIO_PORTE_AFSEL_R	EQU 0x40024420
GPIO_PORTE_PUR_R	EQU 0x40024510
GPIO_PORTE_DEN_R    EQU 0x4002451C

SYSCTL_RCGC2_GPIOB	EQU	0x00000002
GPIO_PORTB_DATA_R	EQU 0x400053FC
GPIO_PORTB_DIR_R	EQU	0x40005400
GPIO_PORTB_AFSEL_R	EQU	0x40005420
GPIO_PORTB_PUR_R	EQU 0x40005510
GPIO_PORTB_DEN_R	EQU	0x4000551C


        AREA    |.text|, CODE, READONLY, ALIGN=2
        THUMB
        EXPORT  Start
		;FSM values
OUT			EQU 0
WAIT		EQU 4
NEXT		EQU 8
W_go		DCD 0x4C					; output value
			DCD 200						; wait time 2s
			DCD W_go, S_wait_W, W_go, S_wait_W, P_wait_W, S_wait_W, P_wait_W, S_wait_W  ; next states
S_wait_W	DCD 0x54
			DCD 100
			DCD S_go, S_go, S_go, S_go, PS_go, PS_go, PS_go, PS_go
S_go		DCD 0x61
			DCD 200
			DCD S_go, S_go, W_wait_S, W_wait_S, P_wait_S, P_wait_S, P_wait_S, P_wait_S
PS_go		DCD 0x61
			DCD 200
			DCD P_wait_S, P_wait_S, P_wait_S, P_wait_S, P_wait_S, P_wait_S, P_wait_S, P_wait_S
P_wait_W	DCD 0x54
			DCD 100
			DCD P_go, P_go, P_go, P_go, P_go, P_go, P_go, P_go
PW_go		DCD 0x4C
			DCD 200
			DCD	P_wait_W, S_wait_W, P_wait_W, S_wait_W, P_wait_W, S_wait_W, P_wait_W, S_wait_W
			;DCD P_wait_W, PS_go, P_wait_W, PS_go, P_wait_W, PS_go, P_wait_W, PS_go
W_wait_S	DCD 0x62
			DCD 100
			DCD W_go, W_go, W_go, W_go, PW_go, PW_go, PW_go, PW_go
P_wait_S	DCD 0x62
			DCD 100
			DCD P_go, P_go, P_go, P_go, P_go, P_go, P_go, P_go
P_go		;DCD 0x24
			DCD 0x36
			DCD 200
			DCD P_go, S_wait_P1, W_wait_P1, W_wait_P1, P_go, S_wait_P1, W_wait_P1, W_wait_P1
W_wait_P1	DCD 0x64
			DCD 50
			DCD W_wait_P2, W_wait_P2, W_wait_P2, W_wait_P2, W_wait_P2, W_wait_P2, W_wait_P2, W_wait_P2
W_wait_P2	DCD 0x24
			DCD 50
			DCD W_wait_P3, W_wait_P3, W_wait_P3, W_wait_P3, W_wait_P3, W_wait_P3, W_wait_P3, W_wait_P3
W_wait_P3	DCD 0x64
			DCD 50
			DCD W_wait_P4, W_wait_P4, W_wait_P4, W_wait_P4, W_wait_P4, W_wait_P4, W_wait_P4, W_wait_P4
W_wait_P4	DCD 0x24
			DCD 50
			DCD W_go, W_go, W_go, W_go, PW_go, PW_go, PW_go, PW_go
S_wait_P1	DCD 0x64
			DCD 50
			DCD S_wait_P2, S_wait_P2, S_wait_P2, S_wait_P2, S_wait_P2, S_wait_P2, S_wait_P2, S_wait_P2
S_wait_P2	DCD 0x24
			DCD 50
			DCD S_wait_P3, S_wait_P3, S_wait_P3, S_wait_P3, S_wait_P3, S_wait_P3, S_wait_P3, S_wait_P3
S_wait_P3	DCD 0x64
			DCD 50
			DCD S_wait_P4, S_wait_P4, S_wait_P4, S_wait_P4, S_wait_P4, S_wait_P4, S_wait_P4, S_wait_P4
S_wait_P4	DCD 0x24
			DCD 50
			DCD S_go, S_go, S_go, S_go, PS_go, PS_go, PS_go, PS_go

Start
		BL  PLL_Init                    ; set system clock to 50 MHz
		BL	SysTick_Init
		BL	Init_Ports
		LDR R8, =GPIO_PORTE_DATA_R
		LDR R4, =W_go					; initial state pointer
		LDR R6, =GPIO_PORTB_DATA_R
		LDR R5, =GPIO_PORTG_DATA_R
FSM		LDR R0, [R4, #OUT]				; output value
		STR R0, [R6]					; store interfaced LED values in B data_R
		AND R0, R0, #0x40				; isolate Don't Walk sign output bit
		LSR R0, R0, #4					; put DW sign output in bit 2
		STR R0, [R5]					; store output value to PG2
		LDR R0, [R4, #WAIT]				; time delay
		BL  SysTick_Wait10ms
		LDR R7, [R5]					; R7 = [R5]
		AND R7, R7, #0x30				; R7&0x30 (isolate PG4,PG5)
		LSR R7, R7, #4					; PG4,PG5 moved to bits 0,1
		EOR R7, R7, #0x03				; flip from negative logic to positive logic
		LDR R0, [R8]					; R0 = [R8]
		AND R0, R0, #0x01				; R0&0x01 (isolate PE0)
		LSL R0, R0, #2					; Shift PE0 to bit 2
		ADD R0, R0, R7					; R0 = inputs ... XXX = (walk,west,south)
		LSL R0, R0, #2
		ADD R0, R0, #NEXT
		LDR R4, [R4,R0]					; R4 = next state
		B   FSM

;-------------Init Ports------------------------
; Initiates ports
; Input: None
; Output: None
; Modifies R0, R1
Init_Ports
	;Port G
	; activate clock for Port G
    LDR R1, =SYSCTL_RCGC2_R         ; R1 = &SYSCTL_RCGC2_R
    LDR R0, [R1]                    ; R0 = [R1]
    ORR R0, R0, #SYSCTL_RCGC2_GPIOG ; R0 = R0|SYSCTL_RCGC2_GPIOG
    STR R0, [R1]                    ; [R1] = R0
    NOP
    NOP                             ; allow time to finish activating
    ; set direction register
    LDR R1, =GPIO_PORTG_DIR_R       ; R1 = &GPIO_PORTG_DIR_R
    LDR R0, [R1]                    ; R0 = [R1]
    ORR R0, R0, #0x04               ; R0 = R0|0x04 (make PG2 output)
	BIC R0, R0, #0x30				; Clears bits 4 and 5 (make PG4,PG5 input)
    STR R0, [R1]                    ; [R1] = R0
	; pull-up resistors on switch pins
    LDR R1, =GPIO_PORTG_PUR_R       ; R1 = &GPIO_PORTG_PUR_R
    LDR R0, [R1]                    ; R0 = [R1]
    ORR R0, R0, #0x30               ; R0 = R0|0x30 (enable pull-up on PG4-5)
    STR R0, [R1]                    ; [R1] = R0
    ; regular port function
    LDR R1, =GPIO_PORTG_AFSEL_R     ; R1 = &GPIO_PORTG_AFSEL_R
    LDR R0, [R1]                    ; R0 = [R1]
    BIC R0, R0, #0x34               ; R0 = R0&~0x34 (disable alt funct on PG2,PG4-5)
    STR R0, [R1]                    ; [R1] = R0
    ; enable digital port
    LDR R1, =GPIO_PORTG_DEN_R       ; R1 = &GPIO_PORTG_DEN_R
    LDR R0, [R1]                    ; R0 = [R1]
    ORR R0, R0, #0x34               ; R0 = R0|0x34 (enable digital I/O on PG2,PG4-5)
    STR R0, [R1]                    ; [R1] = R0
	
	;Port E
	; activates clock for port E
	LDR R1, =SYSCTL_RCGC2_R         ; R1 = &SYSCTL_RCGC2_R
    LDR R0, [R1]                    ; R0 = [R1]
    ORR R0, R0, #SYSCTL_RCGC2_GPIOE ; R0 = R0|SYSCTL_RCGC2_GPIOE
    STR R0, [R1]                    ; [R1] = R0
    NOP
    NOP                             ; allow time to finish activating
	; set direction register
    LDR R1, =GPIO_PORTE_DIR_R       ; R1 = &GPIO_PORTE_DIR_R
    LDR R0, [R1]                    ; R0 = [R1]
    BIC R0, R0, #0x01               ; R0 = R0&~0x01 (make PE0 input; PE0 outside switch)
    STR R0, [R1]                    ; [R1] = R0
    ; regular port function
    LDR R1, =GPIO_PORTE_AFSEL_R     ; R1 = &GPIO_PORTG_AFSEL_R
    LDR R0, [R1]                    ; R0 = [R1]
    BIC R0, R0, #0x01               ; R0 = R0&~0x01 (disable alt funct on PE0)
    STR R0, [R1]                    ; [R1] = R0
    ; enable digital port
    LDR R1, =GPIO_PORTE_DEN_R       ; R1 = &GPIO_PORTE_DEN_R
    LDR R0, [R1]                    ; R0 = [R1]
    ORR R0, R0, #0x01               ; R0 = R0|0x01 (enable digital I/O on PG0)
    STR R0, [R1]
	
	;Port B
	; activates clock for port B
	LDR R1, =SYSCTL_RCGC2_R			; R1 = &SYSCTL_RCGC2_R
	LDR R0, [R1]					; R0 = [R1]
	ORR R0, R0, #SYSCTL_RCGC2_GPIOB	; R0 = R0|SYSCTL_RCGC2_GPIOB
	STR R0, [R1]
	NOP
	NOP
	; set direction register
	LDR R1, =GPIO_PORTB_DIR_R		; R1 = &GPIO_PORTE_DIR_R
	LDR R0, [R1]					; R0 = [R1]
	ORR R0, R0, #0x3F               ; R0 = R0|0x3F (make PB0-5 output)
	STR R0, [R1]					; [R1] = R0
	; regular port function
	LDR R1, =GPIO_PORTB_AFSEL_R		; R1 = &GPIO_PORTB_AFSEL_R
	LDR R0, [R1]					; R0 = [R1]
	BIC R0, R0, #0x3F				; R0 = &~0x3F (disable alt function on P0-5)
	STR R0, [R1]					; [R1] = R0
	; enable digital port
	LDR R1, =GPIO_PORTB_DEN_R		; R1 = &GPIO_PORTB_DEN_R
	LDR R0, [R1]					; R0 = [R1]
	ORR R0, R0, #0x3F				; enable P0-5
	STR R0, [R1]
	
    BX  LR                          ; return


    ALIGN                           ; make sure the end of this section is aligned
    END                             ; end of file
