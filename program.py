import re

add1 = 'add r\d, r\d, #\d'
add2 = 'add r\d, #\d'
add3 = 'add r\d, r\d, r\d'
add4 = 'add r\d, pc'
add5 = 'add r\d, sp'
add6 = 'add sp, #\d'

_and = 'and r\d, r\d'

adr1 = 'asr r\d, r\d, #\d'
adr2 = 'asr r\d, r\d'

b = 'b _'
bne = 'bne \d'
beq = 'beq \d'
bgt = 'bgt \d'
blt = 'blt \d'
bge = 'bge \d'
ble = 'ble \d'

bic = 'bic r\d, r\d'

bl = 'bl \d'

bx = 'bx \d'

cmn = 'cmn r\d, r\d'

cmp1 = 'cmp r\d, #\d'
cmp2 = 'cmp r\d, r\d'

eor = 'eor r\d, r\d'

ldmia = 'ldmia r\d!'

_ldr1 = 'ldr r\d, [r\d, #'
_ldr2 = 'ldr r\d, [r\d, r\d]'
_ldr3 = 'ldr r\d, [pc, #'
_ldr4 = 'ldr r\d, [sp, #'

lsl1 = 'lsl r\d, r\d, #\d'
lsl2 = 'lsl r\d, r\d'

lsr1 = 'lsr r\d, r\d, #\d'
lsr2 = 'lsr r\d, r\d'

mov1 = 'mov r\d, #\d'
mov2 = 'mov r\d, r\d'

mul = 'mul r\d, r\d'

mvn = 'mvn r\d, r\d'

neg = 'neg r\d, r\d'

orr = 'orr r\d, r\d'

pop = 'pop \d'

push = 'push \d'

ror = 'ror r\d, r\d'

sbc = 'sbc r\d, r\d'

sub1 = 'sub r\d, r\d, #\d'
sub2 = 'sub r\d, #\d'
sub3 = 'sub r\d, r\d, r\d'
sub4 = 'sub sp, #\d'
sub5 = 'sub r\d, r\d'

swi = 'swi \d'

tst = 'tst r\d, r\d'

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
