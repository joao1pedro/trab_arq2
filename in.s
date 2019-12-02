str r7, r4, r1
str r7, r2, #1
cmp r4, r2
cmp r2, #1
ldr r0, r1, #1
ldr r0, pc, #1
strb r0, r1, #2
strb r2, r7, r4
swi #2