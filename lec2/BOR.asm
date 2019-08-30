;Basic Output Routine
            .ORIG   x3000
            LD      R1, DATA
POLL        LDI     R0, DSR_ADDR   ; R0<-MEM[MEM[KBSR_ADDR]]
            BRzp    POLL
            STI     R1, DDR_ADDR
            HALT
DSR_ADDR   .FILL   xFE04
DDR_ADDR   .FILL   xFE06
DATA        .FILL   x0043
            .END
