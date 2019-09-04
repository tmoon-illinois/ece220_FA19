;Display a string 
;R0 : Check DSR
;R1 : Character to display
;R2 : string pointer
            .ORIG   x3000
            LEA     R2, MyStr      ;Load the addr of string (R2)
LOOP        LDR     R1, R2, #0      ;Load the character (R1) pointed by R2
            BRz     STOP            ;Halt if null character
POLL        LDI     R0, DSR_ADDR    ;Basic Output Routine
            BRzp    POLL
            STI     R1, DDR_ADDR
            ADD     R2, R2, #1      ;Update the pointer
            BRnzp   LOOP
STOP        HALT
MyStr       .STRINGZ    "ECE220"
DSR_ADDR    .FILL   xFE04
DDR_ADDR    .FILL   xFE06
            .END
