;Display a string 
;R0 : Check DSR
;R1 : Character to display
;R2 : string pointer
            .ORIG   x3000
            LEA     R0, MyStr      ;Load the addr of string (R2)
            PUTS
STOP        HALT
MyStr       .STRINGZ    "ECE220"
DSR_ADDR    .FILL   xFE04
DDR_ADDR    .FILL   xFE06
            .END
