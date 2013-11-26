; IO.s

; Runs on LM3S1968

; EE319K lab 6 device driver for the switch and LED

; You are allowed to use any switch and any LED,

; although the Lab suggests the Select switch PG7 and Status LED PG2

; Valvano

; March 2, 2013 (Spring 2013 version)

 

        EXPORT   IO_Init

        EXPORT   IO_Touch

        EXPORT   IO_HeartBeat

 

 

PG7                EQU 0x40026200

PG2                EQU 0x40026010

GPIO_PORTG_DATA_R  EQU 0x400263FC

GPIO_PORTG_DIR_R   EQU 0x40026400

GPIO_PORTG_AFSEL_R EQU 0x40026420

GPIO_PORTG_PUR_R   EQU 0x40026510

GPIO_PORTG_DEN_R   EQU 0x4002651C

SYSCTL_RCGC2_R     EQU 0x400FE108

SYSCTL_RCGC2_GPIOG EQU 0x00000040   ; port G Clock Gating Control

COUNT10                                               EQU 125000

 

      AREA    |.text|, CODE, READONLY, ALIGN=2

      THUMB

      ALIGN         

 

;------------IO_Init------------

; Activate Port and initialize it for switch and LED

; Input: none

; Output: none

; This is a public function

; Invariables: This function must not permanently modify registers R4 to R11

IO_Init

   ;Port G Initialization

;Activate Port G clock

                LDR R1, =SYSCTL_RCGC2_R                                          ;Load address of the clock into R1

                LDR R0, [R1]                                                                        ;Load the data in the clock address into R0

                ORR R0, #SYSCTL_RCGC2_GPIOG                             ;R0 or x40 sets the 3rd pin to 1

                STR R0, [R1]                                                                        ;Store R0 back in the clock address

                NOP

                NOP

;Set direction register

                LDR R1, =GPIO_PORTG_DIR_R                  

                LDR R0, [R1]

                ORR R0, #0x04                                                                   ;Enable PG2 as output

                BIC R0, #0x80                                                                     ;Enable PG7 as input

                STR R0, [R1]

;Disable Alternate Functions on PG2 and PG7

                LDR R1,=GPIO_PORTG_AFSEL_R

                LDR R0,[R1]

                BIC R0, #0x84                                                                     ;Clear bits 7 and 2

                STR R0,[R1]

;Enable pins PG2 and PG7

                LDR R1,=GPIO_PORTG_DEN_R                  ;Load the address of the enable register into R1

                LDR R0,[R1]                                                                                         ;Load the enable data into R0

                ORR R0,#0x84                                                                    ;Set PG7 PG2 to 1

                STR R0,[R1]                        

               

    BX  LR                          ; return

;------------IO_Touch------------

; wait for release and touch

; Input: none

; Output: none

; This is a public function

; Invariables: This function must not permanently modify registers R4 to R11

IO_Touch 

       PUSH  {R0-R2,R4,LR}

                   LDR R0,=PG7

Again  LDR R1,[R0]

                   CMP R1,#0x80

                   BEQ Again

       LDR R2,=COUNT10                                                                    ;Delays 10 ms

Del10  ADDS R2,#-1

                   BNE Del10

STILL  LDR R1,[R0]

                   CMP R1,#0x80

                   BNE STILL            

       POP  {R0-R2,R4,PC}

 

;------------IO_HeartBeat------------

; toggles an LED

; Input: none

; Output: none

; This is a public function

; Invariables: This function must not permanently modify registers R4 to R11

IO_HeartBeat

                   LDR R0,=PG2

                   LDR R1,[R0]

                   EOR R1,#0x04                                                 ;Toggle PG2

                   STR R1,[R0]

                  

       BX   LR

 

 

   

    ALIGN

    END                             ; end of file