        
        .ORIG       x3000

        ;
        LEA         R0, MyISR
        STI         R0, KBINTV  ;Overwrite the IVT table with my ISR
        ;Enable IE of KBSR, enable Interrupt-driven I/O
        LD          R0, EN_IE
        STI         R0, KBSR



AGAIN
        LD          R0, CapA
        OUT
        BRnzp       AGAIN

MyISR
        ST          R7, SaveR7
        LDI         R0, KBDR
        HALT
        LD          R7, SaveR7
        RTI



EN_IE   .FILL       x4000   ;   0100_0000_0000_0000
CapA    .FILL       x0041
KBSR    .FILL       xFE00
KBDR    .FILL       xFE02
SaveR7  .BLKW       #1
KBINTV  .FILL       x0180

        .END

