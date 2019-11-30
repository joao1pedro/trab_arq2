mov r3, #0
.loop:
    add r3, #1
    sub r0, r1
    ldr r0, [r1, #800800]
    bge .loop
    add r0, r3, #0x8000f
    sub r3, #1
b .label
    add r2, r0, r1
    add r2, r1, #100
    b . 
