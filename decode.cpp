#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

int main () {
  string line;
  ifstream in ("in.s");
  ofstream out;

  regex add1("(add r(\\d), r(\\d), #(.*))");
  regex add2("(add r(\\d), #(.*))");
  regex add3("(add r(\\d), r(\\d), r[0-9])");
  regex add4("(add r(\\d), pc)");
  regex add5("(add r(\\d), sp)");
  regex add6("(add sp, #(.*))");

  regex _and("(and r(\\d), r(\\d))");

  regex asr1("(asr r(\\d), r(\\d), #(.*))");
  regex asr2("(asr r(\\d), r(\\d))");

  regex b("(b \\.\\w)");
  regex _b("(b .\\s)");
  regex bne("(bne (.*))");
  regex beq("(beq (.*))");
  regex bgt("(bgt (.*))");
  regex blt("(blt (.*))");
  regex bge("(bge (.*))");
  regex ble("(ble (.*))");

  regex bic("(bic (.*))");

  regex bl("(bl (.*))");
  
  regex bx("(bx (.*))");

  regex cmn("(cmn r(\\d), r(\\d))");

  regex cmp1("(cmp r(\\d), #(.*))");
  regex cmp2("(cmp r(\\d), r(\\d))");

  regex eor("(eor r(\\d), r(\\d))");
  
  regex ldmia("(ldmia r(\\d)!)");


  regex ldr1("(ldr r(\\d), (\\[)r(\\d), #(.*))");
  regex ldr2("(ldr r(\\d), (\\[)r(\\d), r(\\d))");
  regex ldr3("(ldr r(\\d), (\\[)pc, #(.*))");
  regex ldr4("(ldr r(\\d), (\\[)sp, #(.*))");

  regex lsl1("(lsl r(\\d), r(\\d), #(.*))");
  regex lsl2("(lsl r(\\d), r(\\d))");
  
  regex lsr1("(lsl r(\\d), r(\\d), #(.*))");
  regex lsr2("(lsl r(\\d), r(\\d))");

  regex mov1("(mov r(\\d), #(.*))");
  regex mov2("(mov r(\\d), r(\\d))");


  regex mul("(mul r(\\d), r(\\d))");

  regex mvn("(mvn r(\\d), r(\\d))");
  
  regex neg("(neg r(\\d), r(\\d))");
  
  regex orr("(orr r(\\d), r(\\d))");
  
  regex pop("(pop (.*))");
  
  regex push("(push (.*))");

  regex ror("(ror r(\\d), r(\\d))");
  
  regex sbc("(sbc r(\\d), r(\\d))");
  
  regex sub1("(sub r(\\d), r(\\d), #(.*))");
  regex sub2("(sub r(\\d), #(.*))");
  regex sub3("(sub r(\\d), r(\\d), r(\\d))");
  regex sub4("(sub sp, #(.*))");
  regex sub5("(sub r(\\d), r(\\d))");
  
  regex swi("(swi (.*))");
  regex tst("(tst r[0-9], r[0-9])");

  smatch m;

  if(in.is_open())
  {
    out.open("out.txt");
    while ( getline (in,line) )
    {
        if(regex_search(line, m, add1))
        {
            out << "add1\n";  
        }
        if(regex_search(line, m, add2))
        {
            out << "add2\n";  
        }
        if(regex_search(line, m, add3))
        {
            out << "add3\n";  
        }
        if(regex_search(line, m, add4))
        {
            out << "add4\n";  
        }
        if(regex_search(line, m, add5))
        {
            out << "add5\n";  
        }
        if(regex_search(line, m, add6))
        {
            out << "add6\n";  
        }
        if(regex_search(line, m, _and))
        {
            out << "and\n";  
        }
        if(regex_search(line, m, b))
        {
            out << "b1\n";  
        }
        if(regex_search(line, m, _b))
        {
            out << "b2\n";  
        }
        if(regex_search(line, m, bne))
        {
            out << "bne\n";  
        }
        if(regex_search(line, m, beq))
        {
            out << "beq\n";  
        }
        if(regex_search(line, m, bgt))
        {
            out << "bgt\n";  
        }
        if(regex_search(line, m, blt))
        {
            out << "blt\n";  
        }
        if(regex_search(line, m, bge))
        {
            out << "bge\n";  
        }
        if(regex_search(line, m, bic))
        {
            out << "bic\n";  
        }
        if(regex_search(line, m, bl))
        {
            out << "bl\n";  
        }
        if(regex_search(line, m, bx))
        {
            out << "bx\n";  
        }
        if(regex_search(line, m, cmn))
        {
            out << "cmn\n";  
        }
        if(regex_search(line, m, cmp1))
        {
            out << "cmp1\n";  
        }
        if(regex_search(line, m, cmp2))
        {
            out << "cmp2\n";  
        }
        if(regex_search(line, m, eor))
        {
            out << "eor\n";  
        }
        if(regex_search(line, m, ldmia))
        {
            out << "ldmia\n";  
        }
        if(regex_search(line, m, ldr1))
        {
            out << "ldr1\n";  
        }
        if(regex_search(line, m, ldr2))
        {
            out << "ldr2\n";  
        }
        if(regex_search(line, m, ldr3))
        {
            out << "ldr3\n";  
        }
        if(regex_search(line, m, ldr4))
        {
            out << "ldr4\n";  
        }
        if(regex_search(line, m, lsl1))
        {
            out << "lsl1\n";  
        }
        if(regex_search(line, m, lsl2))
        {
            out << "lsl2\n";  
        }
        if(regex_search(line, m, lsr1))
        {
            out << "lsr1\n";  
        }
        if(regex_search(line, m, lsr2))
        {
            out << "lsr2\n";  
        }
        if(regex_search(line, m, mov1))
        {
            out << "mov1\n";  
        }
        if(regex_search(line, m, mov2))
        {
            out << "mov2\n";  
        }
        if(regex_search(line, m, mul))
        {
            out << "mul\n";  
        }
        if(regex_search(line, m, mvn))
        {
            out << "mvn\n";  
        }
        if(regex_search(line, m, neg))
        {
            out << "neg\n";  
        }
        if(regex_search(line, m, orr))
        {
            out << "orr\n";  
        }
        if(regex_search(line, m, pop))
        {
            out << "pop\n";  
        }
        if(regex_search(line, m, push))
        {
            out << "push\n";  
        }
        if(regex_search(line, m, ror))
        {
            out << "ror\n";  
        }
        if(regex_search(line, m, sbc))
        {
            out << "sbc\n";  
        }
        if(regex_search(line, m, sub1))
        {
            out << "sub1\n";  
        }
        if(regex_search(line, m, sub2))
        {
            out << "sub2\n";  
        }
        if(regex_search(line, m, sub3))
        {
            out << "sub3\n";  
        }
        if(regex_search(line, m, sub4))
        {
            out << "sub4\n";  
        }
        if(regex_search(line, m, sub5))
        {
            out << "sub5\n";  
        }
        if(regex_search(line, m, swi))
        {
            out << "swi\n";  
        }
        if(regex_search(line, m, tst))
        {
            out << "tst\n";  
        }
    }
    out.close();
    in.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}
