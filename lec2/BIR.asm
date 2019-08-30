;Basic Input Routine            
            .ORIG   x3000
POLL        LDI     R0, KBSR_ADDR   ; R0<-MEM[MEM[KBSR_ADDR]]
            BRzp    POLL
            LDI     R1, KBDR_ADDR
KBSR_ADDR   .FILL   xFE00
KBDR_ADDR   .FILL   xFE02
            .END
