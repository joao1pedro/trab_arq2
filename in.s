mov r3, #0
.loop:
    add r3, #1
    sub r0, r1
    bge .loop
    sub r3, #1
    add r2, r0, r1
    add r2, r1, #100
    b .
