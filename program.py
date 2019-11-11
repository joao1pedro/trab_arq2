import re

add1 = 'add r\w, r\w, #\w'
add2 = 'add r\w, #\w'
add3 = 'add r\w, r\w, r\w'
add4 = 'add r\w, pc'
add5 = 'add r\w, sp'
add6 = 'add sp, #w'

_and = 'and r\w, r\w'

adr1 = 'asr r\w, r\w, #\w'
adr2 = 'asr r\w, r\w'

b = 'b _'
bne = 'bne \w'
beq = 'beq \w'
bgt = 'bgt \w'
blt = 'blt \w'
bge = 'bge \w'
ble = 'ble \w'

bic = 'bic r\w, r\w'

bl = 'bl \w'

bx = 'bx \w'

cmn = 'cmn r\w, r\w'

cmp1 = 'cmp r\w, #\w'
cmp2 = 'cmp r\w, r\w'

eor = 'eor r\w, r\w'

ldmia = 'ldmia r\w!'

_ldr1 = 'ldr r\w, [r\w, #'
_ldr2 = 'ldr r\w, [r\w, r\w]'
_ldr3 = 'ldr r\w, [pc, #'
_ldr4 = 'ldr r\w, [sp, #'

lsl1 = 'lsl r\w, r\w, #\w'
lsl2 = 'lsl r\w, r\w'

lsr1 = 'lsr r\w, r\w, #\w'
lsr2 = 'lsr r\w, r\w'

mov1 = 'mov r\w, #\w'
mov2 = 'mov r\w, r\w'

mul = 'mul r\w, r\w'

mvn = 'mvn r\w, r\w'

neg = 'neg r\w, r\w'

orr = 'orr r\w, r\w'

pop = 'pop \w'

push = 'push \w'

ror = 'ror r\w, r\w'

sbc = 'sbc r\w, r\w'

sub1 = 'sub r\w, r\w, #\w'
sub2 = 'sub r\w, #\w'
sub3 = 'sub r\w, r\w, r\w'
sub4 = 'sub sp, #\w'
sub5 = 'sub r\w, r\w'

swi = 'swi \w'

tst = 'tst r\w, r\w'

arquivo = open('in.s','r')
contador = 0
out = open('out.txt', 'a')
for linha in arquivo:
    linha = linha.rstrip()
    if re.search(add1,linha):
        tout = 'add1'
        out.write(tout + '\n')
    if re.search(add2,linha):
        tout = 'add2'
        out.write(tout + '\n')
    if re.search(add3,linha):
        tout = 'add3'
        out.write(tout + '\n')
    if re.search(add4,linha):
        tout = 'add4'
        out.write(tout + '\n')
    if re.search(add5,linha):
        tout = 'add5'
        out.write(tout + '\n')
    if re.search(add6,linha):
        tout = 'add6'
        out.write(tout + '\n')
    if re.search(_and,linha):
        tout = 'and'
        out.write(tout + '\n')
    if re.search(adr1,linha):
        tout = 'adr1'
        out.write(tout + '\n')
    if re.search(adr2,linha):
        tout = 'adr2'
        out.write(tout + '\n')
    if re.search(b,linha):
        tout = 'b'
        out.write(tout + '\n')
    if re.search(bne,linha):
        tout = 'bne'
        out.write(tout + '\n')
    if re.search(beq,linha):
        tout = 'beq'
        out.write(tout + '\n')
    if re.search(bgt,linha):
        tout = 'bgt'
        out.write(tout + '\n')
    if re.search(blt,linha):
        tout = 'blt'
        out.write(tout + '\n')
    if re.search(bge,linha):
        tout = 'bge'
        out.write(tout + '\n')
    if re.search(ble,linha):
        tout = 'ble'
        out.write(tout + '\n')
    if re.search(bic,linha):
        tout = 'bic'
        out.write(tout + '\n')
    if re.search(bl,linha):
        tout = 'bl'
        out.write(tout + '\n')
    if re.search(bx,linha):
        tout = 'bx'
        out.write(tout + '\n')
    if re.search(cmn,linha):
        tout = 'cmn'
        out.write(tout + '\n')
    if re.search(cmp1,linha):
        tout = 'cmp1'
        out.write(tout + '\n')
    if re.search(cmp2,linha):
        tout = 'cmp2'
        out.write(tout + '\n')
    if re.search(eor,linha):
        tout = 'eor'
        out.write(tout + '\n')
    if re.search(ldmia,linha):
        tout = 'ldmia'
        out.write(tout + '\n')
    '''
    if re.search(_ldr1,linha):
        tout = 'ldr1'
        out.write(tout + '\n')
    if re.search(_ldr2,linha):
        tout = 'ldr2'
        out.write(tout + '\n')
    if re.search(_ldr3,linha):
        tout = 'ldr3'
        out.write(tout + '\n')
    if re.search(_ldr4,linha):
        tout = 'ldr4'
        out.write(tout + '\n')
    '''
    if re.search(lsl1,linha):
        tout = 'lsl1'
        out.write(tout + '\n')
    if re.search(lsl2,linha):
        tout = 'lsl2'
        out.write(tout + '\n')
    if re.search(lsr1,linha):
        tout = 'lsr1'
        out.write(tout + '\n')
    if re.search(lsr2,linha):
        tout = 'lsr2'
        out.write(tout + '\n')
    if re.search(mov1,linha):
        tout = 'mov1'
        out.write(tout + '\n')
    if re.search(mov2,linha):
        tout = 'mov2'
        out.write(tout + '\n')
    if re.search(mul,linha):
        tout = 'mul'
        out.write(tout + '\n')
    if re.search(mvn,linha):
        tout = 'mvn'
        out.write(tout + '\n')
    if re.search(neg,linha):
        tout = 'neg'
        out.write(tout + '\n')
    if re.search(orr,linha):
        tout = 'orr'
        out.write(tout + '\n')
    if re.search(pop,linha):
        tout = 'pop'
        out.write(tout + '\n')
    if re.search(push,linha):
        tout = 'push'
        out.write(tout + '\n')
    if re.search(ror,linha):
        tout = 'ror'
        out.write(tout + '\n')
    if re.search(sbc,linha):
        tout = 'sbc'
        out.write(tout + '\n')
    if re.search(sub1,linha):
        tout = 'sub1'
        out.write(tout + '\n')
    if re.search(sub2,linha):
        tout = 'sub2'
        out.write(tout + '\n')
    if re.search(sub3,linha):
        tout = 'sub3'
        out.write(tout + '\n')
    if re.search(sub4,linha):
        tout = 'sub4'
        out.write(tout + '\n')
    if re.search(sub5,linha):
        tout = 'sub5'
        out.write(tout + '\n')
    if re.search(swi,linha):
        tout = 'swi'
        out.write(tout + '\n')
    if re.search(tst,linha):
        tout = 'tst'
        out.write(tout + '\n')
out. close
arquivo.close()
