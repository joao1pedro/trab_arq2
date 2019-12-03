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
add r0, r1, r3
sub r0, #1
add r7, sp, #2
<<<<<<< HEAD
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
add r0, r1, r3
sub r0, #1
add r7, sp, #2
=======
swi #2
bkpt #10
revsh r0, r1
uxtb r1, r2
uxth r1, r2
sxtb r1, r0
sxth r4, r7
setend le
setend be
>>>>>>> 4d764d6957b3dfabd1e4c0335ace78ec43ee55aa
