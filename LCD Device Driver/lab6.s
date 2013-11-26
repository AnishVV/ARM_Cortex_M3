; main.s
; Runs on LM3S1968
; Lab 6 Test of LCD driver
; March 2, 2013 (Spring 2013 version)
; Select switch PG7 (negative logic) used to cycle through outputs
; Status LED PG2 (positive logic) used for heart beat

       AREA      DATA, ALIGN=2
; Global variables go here

       ALIGN          
       AREA     |.text|, CODE, READONLY, ALIGN=2
       THUMB
       EXPORT   Start
       IMPORT   PLL_Init
       IMPORT   LCD_Open
       IMPORT   LCD_Clear
       IMPORT   LCD_OutChar
       IMPORT   LCD_GoTo
       IMPORT   LCD_OutString
       IMPORT   LCD_OutChar
       IMPORT   LCD_OutDec
       IMPORT   LCD_OutFix       
       IMPORT   IO_Init
       IMPORT   IO_Touch
       IMPORT   IO_HeartBeat

Start  BL   PLL_Init    ; running at 50 MHz
       BL   LCD_Open    ; ***Your function that initializes LCD interface
       BL   IO_Init     ; ***Your function that initialize switch and LED
   
run    BL   LCD_Clear     ;***Your function that clears the display
       LDR  R0,=Welcome
       BL   LCD_OutString ;***Your function that outputs a string
       LDR  R4,=TestData
       LDR  R5,=TestEnd
       BL   IO_Touch     ;***Your function that waits for release and touch 
loop   BL   IO_HeartBeat ;***Your function that toggles LED
       BL   LCD_Clear    ;***Your function that clears the display
       LDR  R0, [R4]            
       BL   LCD_OutDec   ;***Your function that outputs an integer
       MOV  R0, #0x40    ;Cursor location of the 8th position
       BL   LCD_GoTo     ;***Your function that moves the cursor
       LDR  R0, [R4],#4           
       BL   LCD_OutFix   ;***Your function that outputs a fixed-point
       BL   IO_Touch     ;***Your function that waits for release and touch 
       CMP  R4, R5
       BNE  loop      
       B    run    
       ALIGN          
Welcome  DCB "Welcome "
         DCB "" ;32 spaces
         DCB "to 319K!",0
         ALIGN          
TestData DCD 0,7,34,199,321,654,4789,9999,10000,21896,65535,12345678
TestEnd  DCD 0
         ALIGN                       
         

    ALIGN
    END                             ; end of file
    