        .ORIG       x3000
        LD          R0, Value1
        JSR         PUSH
        LD          R0, Value2
        JSR         PUSH
        LD          R0, Value3
        JSR         PUSH
        LD          R0, Value4
        JSR         PUSH
        LD          R0, Value5
        JSR         PUSH
       
        JSR         POP
        OUT
        JSR         POP
        OUT
        JSR         POP
        OUT
        JSR         POP
        OUT
        JSR         POP
        OUT
        LD          R0, Value5
        JSR         PUSH
        LD          R0, Value5
        JSR         PUSH
        
        HALT

;PUSH subroutine
;IN: R0 (value)
;OUT: R5(0-success, 1-fail)
;R3: STACK_END
;R6: STACK_TOP
PUSH
;Do Callee-save and initialize regs
        ST          R3, SaveR3
        ST          R6, SaveR6
        LD          R3, STACK_END
        LD          R6, STACK_TOS
        AND         R5, R5, #0
;Overflow?
;Check R6 = STACK_END-1
;Or check R6 - (STACK_END-1) = 0
        ADD         R3, R3, #-1
        NOT         R3, R3
        ADD         R3, R3, #1
        ADD         R3, R6, R3
        BRz         OVERFLOW
;No overflow detected
        STR         R0, R6, #0
        ADD         R6, R6, #-1
        ST          R6, STACK_TOS
        BRnzp       DONE_PUSH
;Overflow detetected
OVERFLOW
        ADD         R5, R5, #1
DONE_PUSH
        LD          R3, SaveR3
        LD          R6, SaveR6
        RET
;POP subroutine
;IN: none
;OUT: R0 (value)
;OUT: R5 (0: success, 1: fail)
;R3: STACK_START
;R6: STACK_TOP
POP
;Do Callee-save and initialize regs
        ST          R3, SaveR3
        ST          R6, SaveR6
        LD          R3, STACK_START
        LD          R6, STACK_TOS
        AND         R5, R5, #0
;Underflow?
;Check R6 = STACK_START
;Or check R6 - STACK_START = 0
        NOT         R3, R3
        ADD         R3, R3, #1
        ADD         R3, R6, R3
        BRz         UNDERFLOW
;No underflow detected
        ADD         R6, R6, #1
        LDR         R0, R6, #0
        ST          R6, STACK_TOS
        BRnzp       DONE_POP
;Underflow detetected
UNDERFLOW
        ADD         R5, R5, #1
DONE_POP
        LD          R3, SaveR3
        LD          R6, SaveR6
        RET

;size of STACK is 4
STACK_END   .FILL   x3FFD
STACK_START .FILL   x4000
STACK_TOS   .FILL   x4000
Value1  .FILL       x0041
Value2  .FILL       x0042
Value3  .FILL       x0043
Value4  .FILL       x0044
Value5  .FILL       x0045
SaveR3  .BLKW       #1
SaveR6  .BLKW       #1
        .END
