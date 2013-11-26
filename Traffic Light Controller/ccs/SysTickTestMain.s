; SysTickTestMain.s
; Runs on LM3S1968
; Test the SysTick functions by activating the PLL, initializing the
; SysTick timer, and flashing an LED at a constant rate.
; Daniel Valvano
; February 22, 2012

;  This example accompanies the book
;  "Embedded Systems: Introduction to the Arm Cortex M3",
;  ISBN: 978-1469998749, Jonathan Valvano, copyright (c) 2012
;  Program 4.6, Section 4.3
;  Program 4.7, Section 4.4
;
;Copyright 2012 by Jonathan W. Valvano, valvano@mail.utexas.edu
;   You may use, edit, run or distribute this file
;   as long as the above copyright notice remains
;THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
;OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
;MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
;VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
;OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
;For more information about my classes, my research, and my books, see
;http://users.ece.utexas.edu/~valvano/

        .ref   SysTick_Init
        .ref   SysTick_Wait
        .ref   SysTick_Wait10ms
        .ref   PLL_Init

GPIO_PORTG2        .field 0x40026010
GPIO_PORTG_DIR_R   .field 0x40026400
GPIO_PORTG_AFSEL_R .field 0x40026420
GPIO_PORTG_DEN_R   .field 0x4002651C
SYSCTL_RCGC2_R     .field 0x400FE108
SYSCTL_RCGC2_GPIOG .equ   0x00000040   ; port G Clock Gating Control

    .align 2
	.text
	.thumb
	
	.asg	"main", Start			; 'Start' is an alias for 'main'
	.global Start
	.thumbfunc Start
Start:	.asmfunc		
    BL  PLL_Init                    ; set system clock to 50 MHz
    BL  SysTick_Init                ; initialize SysTick timer
    ; activate clock for Port G
    LDR R1, SYSCTL_RCGC2_R         ; R1 = SYSCTL_RCGC2_R
    LDR R0, [R1]                    ; R0 = [R1]
    ORR R0, R0, #SYSCTL_RCGC2_GPIOG ; R0 = R0|SYSCTL_RCGC2_GPIOG
    STR R0, [R1]                    ; [R1] = R0
    NOP
    NOP                             ; allow time to finish activating
    ; set direction register
    LDR R1, GPIO_PORTG_DIR_R       ; R1 = GPIO_PORTG_DIR_R
    LDR R0, [R1]                    ; R0 = [R1]
    ORR R0, R0, #0x04               ; R0 = R0|0x04 (make PG2 output)
    STR R0, [R1]                    ; [R1] = R0
    ; regular port function
    LDR R1, GPIO_PORTG_AFSEL_R     ; R1 = GPIO_PORTG_AFSEL_R
    LDR R0, [R1]                    ; R0 = [R1]
    BIC R0, R0, #0x04               ; R0 = R0&~0x04 (disable alt funct on PG2) (default setting)
    STR R0, [R1]                    ; [R1] = R0
    ; enable digital port
    LDR R1, GPIO_PORTG_DEN_R       ; R1 = GPIO_PORTG_DEN_R
    LDR R0, [R1]                    ; R0 = [R1]
    ORR R0, R0, #0x04               ; R0 = R0|0x04 (enable digital I/O on PG2) (default setting on LM3S811, not default on other microcontrollers)
    STR R0, [R1]                    ; [R1] = R0
    LDR R4, GPIO_PORTG2            ; R4 = GPIO_PORTG2
    LDR R5, [R4]                    ; R5 = [R4]
loop
    EOR R5, R5, #0x04               ; R5 = R5^0x04 (toggle PG2)
    STR R5, [R4]                    ; [R4] = R5
;    MOV R0, #1                      ; approximately 500 ns
;    MOV R0, #2                      ; approximately 500 ns
;    MOV R0, #10000                  ; approximately 0.2 ms
;    BL  SysTick_Wait
    MOV R0, #1                      ; approximately 10 ms
    BL  SysTick_Wait10ms
    B   loop
    .endasmfunc

    .end                             ; end of file