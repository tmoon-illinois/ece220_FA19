;negate the valie in R0
        .ORIG   x3000
        LD      R0, Value
        JSR     NEG         ;R6 = -R0
        ;BRnzp   NEG
        ADD     R1, R6, R0
        ;HALT
;NEG: R6 = -R0
NEG     ;ST      R0, SaveR0
        NOT     R6, R0
        ADD     R6, R6, #1
        ;LD      R0, SaveR0
        RET

Value   .FILL   #5
SaveR0  .BLKW   #1
        .END
