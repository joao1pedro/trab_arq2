str r7, r4, r1
str r7, r2, #1
cmp r4, r2
cmp r2, #1
ldr r0, r1, #1
ldr r0, pc, #1
strb r0, r1, #2
strb r2, r7, r4
eor r4, r7
and r2, r0
lsl r1, r2
lsr r0, r7
adc r1, r2
ror r1, r0
cmn r1, r2
tst r7, r8
bic r0, r1
mvn r1, r4