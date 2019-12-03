#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include <bits/stdc++.h>
#include <string.h>

#define set(x, y) (x | (1 << y))
#define reset(x, y) (x & ~(1 << y))

using namespace std;

void decode(void);

// for string delimiter
vector<string> split(string s, string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

void decode(void)
{
    string line;
    ifstream in("in.s");
    unsigned short valor = 0;

    if (in.is_open())
    {
        while (getline(in, line))
        {
            transform(line.begin(), line.end(), line.begin(), ::toupper); //tranforma tudo em maiúscula
            vector<string> inst = split(line, " ");
            if (inst[0] == "MOV")
            {
                if (inst[1][0] == 'R'){
                    if (inst[2][0] == '#')
                    { //identificou a instrução MOV da 5º linha da tabela
                        //colocando o valor imediato no short(16 bits) nos 7 primeiros bitis, como diz  tabela
                        valor = 0;
                        inst[2][0] = '0';
                        istringstream(inst[2]) >> valor;
                        valor &= 0b0000000011111111;

                        //colocando o numero do registrador nos bits(8..10)
                        int reg1 = inst[1][1]-48;
                        valor |= reg1 << 8;
                        valor &= 0b0000011111111111;
                        //colocando o restante dos bits com o op(0) já que é a primeira instrução da linha
                        valor |= 0b00100 << 11;
                        printf("%x\n", valor);
                    }else if(inst[2][0] == 'R'){//Linha ? da tabela    
                        valor = 0;
                        int ld = 0;
                        inst[1][0] = '0';
                        istringstream(inst[1]) >> ld;

                        int lm = 0;
                        inst[2][0] = '0';
                        istringstream(inst[2]) >> lm;
                    
                    
                    if(ld < 7){// registrador de destino é ld
                        if(lm > 7){//registrador de origem é Hm
                            valor |= ld;
                            valor &= 0b0000000000000111;

                            lm = lm &= 0b0111;
                            valor |= lm << 3;
                            valor &= 0b0000000000111111;
                            
                            valor |= 0b0100011001 << 6 ; 
                            printf("%x\n", valor);
                        }
                    } else if(lm < 7){//registrador de destino é Hd e o de origem é lm
                        ld = ld &= 0b0111;
                        valor |= ld;//0000000000000011
                        valor &= 0b0000000000000111;

                        valor |= lm << 3;
                        valor &= 0b0000000000111111;
                        
                        valor |= 0b0100011010 << 6 ; 
                        printf("%x\n", valor);
                    }else{//registrador de destino é Hd e o de origem é Hm
                        ld = ld &= 0b0111;
                        valor |= ld;//0000000000000011
                        valor &= 0b0000000000000111;

                        lm = lm &= 0b0111;
                        valor |= lm << 3;
                        valor &= 0b0000000000111111;
                        
                        valor |= 0b0100011011 << 6 ; 
                        printf("%x\n", valor);    
                    }
                }
            }
        }else if (inst[0] == "ADD"){ //linha 6 da tabela
            valor = 0;
            unsigned short aux = 0;
            if(inst[1] == "SP,"){
                if(inst[2][0] == '#'){
                    inst[2][0] = '0';
                    //cout << inst[2] << endl;
                    istringstream(inst[2]) >> aux;

                    aux = aux >> 2; //Divide imediato por 4
                    valor |= aux;   //Coloca o imediato no short valor
                    valor &= 0b0000000001111111;

                    valor |= 0b101100000 << 7;
                    printf("%x\n", valor); 
                }
            }else if(inst[1][0] == 'R'){
                if(inst[2] == "PC,"){
                    if(inst[3][0] == '#'){
                            inst[3][0] = '0';
                            istringstream(inst[3]) >> aux;
                            aux = aux >> 2;
                            valor |= aux; 
                            valor &= 0b0000000011111111;

                            int reg1 = 0;
                            reg1 = inst[1][1] - 48;
                            valor |= reg1 << 8;
                            valor &= 0b0000011111111111;
                            
                            valor |= 0b10100 << 11;
                            printf("%x\n", valor);
                    }
                }else if(inst[2] == "SP,"){
                    if(inst[3][0] == '#'){
                        inst[3][0] = '0';
                        unsigned short aux = 0;
                        istringstream(inst[3]) >> aux;
                        aux = aux >> 2;
                        valor |= aux; 
                        valor &= 0b0000000011111111;

                        int reg1 = 0;
                        reg1 = inst[1][1] - 48;
                        valor |= reg1 << 8;
                        valor &= 0b0000011111111111;
                        
                        valor |= 0b10101 << 11;
                        printf("%x\n", valor);
                    }
                }else if (inst[2][0] == '#'){
                        inst[2][0] = '0';
                        istringstream(inst[2]) >> valor;
                        valor &= 0b0000000011111111;

                        int reg1 = 0;
                        reg1 = inst[1][1] - 48;
                        valor |= reg1 << 8;
                        valor &= 0b0000011111111111;

                        valor |= 0b00110 << 11;
                        printf("%x\n", valor);
                }else if(inst[2][0] == 'R'){ //linha 3 da tabela
                    if(inst.size() == 3){
                        //Linha ? da tabela    
                        valor = 0;
                        int ld = 0;
                        inst[1][0] = '0';
                        istringstream(inst[1]) >> ld;

                        int lm = 0;
                        inst[2][0] = '0';
                        istringstream(inst[2]) >> lm;
                        
                        //linhas 12, 13 e 14
                        if(ld < 7){// registrador de destino é ld
                            if(lm > 7){//registrador de origem é Hm
                                valor |= ld;
                                valor &= 0b0000000000000111;

                                lm = lm &= 0b0111;
                                valor |= lm << 3;
                                valor &= 0b0000000000111111;
                                
                                valor |= 0b0100010001 << 6 ; 
                                printf("%x\n", valor);
                            }
                        } else if(lm < 7){//registrador de destino é Hd e o de origem é lm
                            ld = ld &= 0b0111;
                            valor |= ld;//0000000000000011
                            valor &= 0b0000000000000111;

                            valor |= lm << 3;
                            valor &= 0b0000000000111111;
                            
                            valor |= 0b0100010010 << 6 ; 
                            printf("%x\n", valor);
                        }else{//registrador de destino é Hd e o de origem é Hm
                            ld = ld &= 0b0111;
                            valor |= ld;//0000000000000011
                            valor &= 0b0000000000000111;

                            lm = lm &= 0b0111;
                            valor |= lm << 3;
                            valor &= 0b0000000000111111;
                            
                            valor |= 0b0100010011 << 6 ; 
                            printf("%x\n", valor);    
                        }
                    }else if(inst[3][0] == 'R'){
                        valor = 0;
                        
                        int reg1 = 0;
                        reg1 = inst[1][1] - 48;
                        valor |= reg1 ;
                        valor &= 0b0000000000000111;

                        int reg2 = 0;
                        reg2 = inst[2][1] - 48;
                        valor |= reg2 << 3;
                        valor &= 0b0000000000111111; 

                        int reg3 = 0;
                        reg3 = inst[3][1] - 48;
                        valor |= reg3 << 6;
                        valor &= 0b0000000111111111; 
                        
                        valor |= 0b0001100 << 9;
                        printf("%x\n", valor);
                    }else if(inst[3][0] == '#'){
                        inst[3][0] = '0';
                        istringstream(inst[3]) >> valor;
                        valor = valor << 6;
                        valor &= 0b0000000111000000;

                        int reg1 = 0;
                        reg1 = inst[1][1] - 48;
                        valor |= reg1;
                        valor &= 0b0000000111000111;

                        int reg2 = 0;
                        reg2 = inst[2][1] - 48;
                        valor |= reg2 << 3;
                        valor &= 0b0000000111111111;                            

                        valor |= 0b0001110 << 9;
                        printf("%x\n", valor);       
                    }
                }
            }
            }else if (inst[0] == "SUB"){ //linha 3,4 e 6 da tabela
                valor = 0;
                unsigned short aux = 0;
                if(inst[1] == "SP,"){
                    if(inst[2][0] == '#'){
                        inst[2][0] = '0';
                        //cout << inst[2] << endl;
                        istringstream(inst[2]) >> aux;

                        aux = aux >> 2; //Divide imediato por 4
                        valor |= aux;   //Coloca o imediato no short valor
                        valor &= 0b0000000001111111;

                        valor |= 0b101100001 << 7;
                        printf("%x\n", valor); 
                    }
                }else if (inst[1][0] == 'R'){
                    if (inst[2][0] == '#'){
                        
                        inst[2][0] = '0';
                        istringstream(inst[2]) >> valor;
                        valor &= 0b0000000011111111;

                        int reg1 = 0;
                        reg1 = inst[1][1] - 48;
                        valor |= reg1 << 8;
                        valor &= 0b0000011111111111;

                        valor |= 0b00111 << 11;
                        printf("%x\n", valor);
                    
                    }else if(inst[2][0] == 'R'){
                        if(inst.size() == 3){
                        }else if(inst[3][0] == 'R'){
                            valor = 0;
                            int reg1 = 0;
                            reg1 = inst[1][1] - 48;
                            valor |= reg1 ;
                            valor &= 0b0000000000000111;

                            int reg2 = 0;
                            reg2 = inst[2][1] - 48;
                            valor |= reg2 << 3;
                            valor &= 0b0000000000111111; 

                            int reg3 = 0;
                            reg3 = inst[3][1] - 48;
                            valor |= reg3 << 6;
                            valor &= 0b0000000111111111; 

                            valor |= 0b0001101 << 9;
                            printf("%x\n", valor);
                        }else if(inst[3][0] == '#'){ //linha 4(opcao 1) da tabela
                            inst[3][0] = '0';
                            istringstream(inst[3]) >> valor;
                            valor = valor << 6;
                            valor &= 0b0000000111000000;

                            int reg1 = 0;
                            reg1 = inst[1][1] - 48;
                            valor |= reg1 << 0;
                            valor &= 0b0000000111000111;

                            int reg2 = 0;
                            reg2 = inst[2][1] - 48;
                            valor |= reg2 << 3;
                            valor &= 0b0000000111111111;                            

                            valor |= 0b0001111 << 9;
                            printf("%x\n", valor);       
                        }
                    }
                }   
            }else if(inst[0] == "STR"){//linha 25
                if(inst[1][0] == 'R'){
                    if(inst[2][0] == '['){
                        if(inst[3][0] == '#'){
                            int n = (inst[3].size());
                            if(inst[3][n - 1] == ']'){
                                inst[3][0] = '0'; 
                                for (int i = n - 1; i > 0; i--){
                                    inst[3][i] = inst[3][i - 1];
                                }
                                //cout << inst[3];
                                istringstream(inst[3]) >> valor;
                                valor &= 0b0000000011111111; 
                                //cout << valor << endl;
                                
                                int reg = 0;
                                reg = inst[1][1] - 48;
                                valor |= reg << 8;

                                //cout << valor << endl;
                                
                                valor &= 0b0000011111111111;
                                valor |= 0b10010 << 11;   
                                //cout << valor << endl;
                                
                                unsigned short aux = valor;
                                aux &= 0b0000000011111111;
                                aux = aux >> 2; 
                                valor &= 0b1111111100000000;
                                valor |= aux;
                                printf("%x\n", valor);                                 
                            }
                        }
                    }
                }
            }else if(inst[0] == "LDR"){//linha 25
                valor = 0;
                if(inst[1][0] == 'R'){
                    if(inst[2] == "[SP,"){
                        if(inst[3][0] == '#'){
                            int n = (inst[3].size());
                            if(inst[3][n - 1] == ']'){
                                inst[3][0] = '0';
                                //valor = 0; 
                                for (int i = n - 1; i > 0; i--){
                                    inst[3][i] = inst[3][i - 1];
                                }
                                //cout << inst[3];
                                istringstream(inst[3]) >> valor;
                                valor &= 0b0000000011111111; 
                                //cout << valor << endl;
                                
                                int reg = 0;
                                reg = inst[1][1] - 48;
                                valor |= reg << 8;

                                //cout << valor << endl;
                                
                                valor &= 0b0000011111111111;
                                valor |= 0b10011 << 11;   
                                //cout << valor << endl;
                                
                                unsigned short aux = valor;
                                aux &= 0b0000000011111111;
                                aux = aux >> 2; 
                                valor &= 0b1111111100000000;
                                valor |= aux;
                                printf("%x\n", valor);                                 
                            }
                        }
                    }else if(inst[2] == "[PC,"){
                        if(inst[3][0] == '#'){
                            int n = (inst[3].size());
                            if(inst[3][n - 1] == ']'){
                                inst[3][0] = '0'; 
                                for (int i = n - 1; i > 0; i--){
                                    inst[3][i] = inst[3][i - 1];
                                }
                                //cout << inst[3];
                                istringstream(inst[3]) >> valor;
                                valor &= 0b0000000011111111; 
                                //cout << valor << endl;
                                
                                int reg = 0;
                                reg = inst[1][1] - 48;
                                valor |= reg << 8;

                                //cout << valor << endl;
                                
                                valor &= 0b0000011111111111;
                                valor |= 0b01001 << 11;   
                                //cout << valor << endl;
                                
                                unsigned short aux = valor;
                                aux &= 0b0000000011111111;
                                aux = aux >> 2; 
                                valor &= 0b1111111100000000;
                                valor |= aux;
                                printf("%x\n", valor);    
                            }                             
                        }
                    }
                }
            }else if(inst[0] == "CMP"){//linhas 9, 15, 16 e 17
                valor = 0;
                if(inst[1][0] == 'R'){
                    if(inst[2][0] == 'R'){
                        int reg1 = 0;
                        reg1 = inst[1][1] - 48;
                        valor |= reg1;
                        valor &= 0b0000000000000111;

                        int reg2 = 0;
                        reg2 = inst[2][1] - 48;
                        valor |= reg2 << 3;
                        valor &= 0b0000000000111111;

                        valor |= 0b0100001010 << 6; 
                        printf("%x\n", valor);
                    }
                }else if (inst[1][0] == 'R'){
                    if (inst[2][0] == '#'){
                        inst[2][0] = '0';
                        istringstream(inst[2]) >> valor;
                        valor &= 0b0000000001111111;

                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 8;
                        valor &= 0b0000001111111111;

                        valor |= 0b00101 << 11;
                        printf("%x\n", valor);
                    }else if(inst[2][0] == 'R'){//Linha ? da tabela    
                            valor = 0;
                            int ld = 0;
                            inst[1][0] = '0';
                            istringstream(inst[1]) >> ld;

                            int lm = 0;
                            inst[2][0] = '0';
                            istringstream(inst[2]) >> lm;
                    
                    
                        if(ld < 7){// registrador de destino é ld
                            if(lm > 7){//registrador de origem é Hm
                                valor |= ld;
                                valor &= 0b0000000000000111;

                                lm = lm &= 0b0111;
                                valor |= lm << 3;
                                valor &= 0b0000000000111111;
                                
                                valor |= 0b0100010101 << 6 ; 
                                printf("%x\n", valor);
                            }
                        } else if(lm < 7){//registrador de destino é Hd e o de origem é lm
                            ld = ld &= 0b0111;
                            valor |= ld;//0000000000000011
                            valor &= 0b0000000000000111;

                            valor |= lm << 3;
                            valor &= 0b0000000000111111;
                            
                            valor |= 0b0100010110 << 6 ; 
                            printf("%x\n", valor);
                        }else{//registrador de destino é Hd e o de origem é Hm
                            ld = ld &= 0b0111;
                            valor |= ld;//0000000000000011
                            valor &= 0b0000000000000111;

                            lm = lm &= 0b0111;
                            valor |= lm << 3;
                            valor &= 0b0000000000111111;
                            
                            valor |= 0b0100010111 << 6 ; 
                            printf("%x\n", valor);    
                        }
                    }
                }
            }else if(inst[0] == "MVN"){//linha 10
                valor = 0;
                if(inst[1][0] == 'R'){
                    if(inst[2][0] == 'R'){
                        int reg1 = 0;
                        reg1 = inst[1][1] - 48;
                        valor |= reg1;
                        valor &= 0b0000000000000111;

                        int reg2 = 0;
                        reg2 = inst[2][1] - 48;
                        valor |= reg2 << 3;
                        valor &= 0b0000000000111111;

                        valor |= 0b0100001111 << 6; 
                        printf("%x\n", valor);
                    }
                }            
            }
        }
    }
    in.close();
}

int main(){
    decode();
    return 0;
}