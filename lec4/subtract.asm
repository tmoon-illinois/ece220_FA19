;Subtraction: R1 = R2 - R3
        .ORIG   x3000
        LD      R2,Value1   ;load a value into R2
        LD      R3,Value2   ;load a value into R3
        JSR     SUBTR       ;jump to subroutine
        HALT
;NEG: R6 = -R0
NEG     
        NOT     R6, R0
        ADD     R6, R6, #1
        RET
;SUBTR: R1 = R2 - R3
SUBTR   
        ST      R0, SaveR0
        ST      R7, SaveR7
        ADD     R0, R3, #0
        JSR     NEG
        ADD     R1, R2, R6
        LD      R0, SaveR0
        LD      R7, SaveR7
        RET
Value1  .FILL   #5
Value2  .FILL   #4
SaveR0  .BLKW   #1
SaveR7  .BLKW   #1
        .END
