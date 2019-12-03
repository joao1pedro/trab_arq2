#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include <bits/stdc++.h>

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

    short valor = 0;

    if (in.is_open())
    {
        while (getline(in, line))
        {
            transform(line.begin(), line.end(), line.begin(), ::toupper); //tranforma tudo em maiúscula
            vector<string> inst = split(line, " ");
            if (inst[0] == "MOV")
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == '#')
                    { //identificou a instrução MOV da 5º linha da tabela
                        //colocando o valor imediato no short(16 bits) nos 7 primeiros bitis, como diz  tabela
                        inst[2][0] = '0';
                        istringstream(inst[2]) >> valor;
                        valor &= 0b0000000001111111;

                        //colocando o numero do registrador nos bits(8..10)
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 8;
                        valor &= 0b0000001111111111;

                        //colocando o restante dos bits com o op(0) já que é a primeira instrução da linha
                        valor |= 0b00100 << 11;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "CMP") //linha 5
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == '#')
                    {
                        inst[2][0] = '0';
                        istringstream(inst[2]) >> valor;
                        valor &= 0b0000000001111111;

                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 8;
                        valor &= 0b0000001111111111;

                        valor |= 0b00101 << 11;
                        printf("%x\n", valor);
                    }
                    else if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        reg = inst[2][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        valor |= 0b010001010 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "ADD") //linha 6
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == '#')
                    {
                        inst[2][0] = '0';
                        istringstream(inst[2]) >> valor;
                        valor &= 0b0000000001111111;

                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 8;
                        valor &= 0b0000001111111111;

                        valor |= 0b00110 << 11;
                        printf("%x\n", valor);
                    }
                }
                else if (inst[1][0] == 'S')
                {
                    if (inst[2][0] == '#')
                    { //identificou a instrução MOV da 5º linha da tabela
                        //colocando o valor imediato no short(16 bits) nos 7 primeiros bitis, como diz  tabela
                        inst[2][0] = '0';
                        istringstream(inst[2]) >> valor;
                        valor &= 0b00111111;

                        //colocando o restante dos bits com o op(0) já que é a primeira instrução da linha
                        valor |= 0b101100000 << 7;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "SUB") //linha 6
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == '#')
                    {
                        inst[2][0] = '0';
                        istringstream(inst[2]) >> valor;
                        valor &= 0b0000000001111111;

                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 8;
                        valor &= 0b0000001111111111;

                        valor |= 0b00111 << 11;
                        printf("%x\n", valor);
                    }
                }
                else if (inst[1][0] == 'S')
                {
                    if (inst[2][0] == '#')
                    {
                        inst[2][0] = '0';
                        istringstream(inst[2]) >> valor;
                        valor &= 0b00111111;

                        valor |= 0b101100001 << 7;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "ASR") //linha 2
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        if (inst[3][0] == '#')
                        {
                            ///rd
                            int reg = 0;
                            reg = inst[1][1] - 48;
                            valor |= reg << 8;
                            valor &= 0b0011;

                            //rn
                            reg = inst[2][1] - 48;
                            valor |= reg << 8;
                            valor &= 0b000011000;

                            inst[3][0] = '0';
                            istringstream(inst[3]) >> valor;
                            valor &= 0b001111000000;

                            //colocando o restante dos bits com o op(0) já que é a primeira instrução da linha
                            valor |= 0b00010 << 11;
                            printf("%x\n", valor);
                        }
                        else
                        {//linha 8
                            int reg = 0;
                            reg = inst[1][1] - 48;
                            valor |= reg << 5;
                            valor &= 0b00011000;

                            reg = inst[2][1] - 48;
                            valor |= reg << 2;
                            valor &= 0b0011;

                            valor |= 0b010000100 << 6;
                            printf("%x\n", valor);
                        }
                    }
                }
            }
            else if (inst[0] == "LSL") //linha 1
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    { //identificou a instrução ASR da 5º linha da tabela
                        if (inst[3][0] == '#')
                        {
                            ///rd
                            int reg = 0;
                            reg = inst[1][1] - 48;
                            valor |= reg << 2;
                            valor &= 0b0011;

                            //rn
                            reg = inst[2][1] - 48;
                            valor |= reg << 5;
                            valor &= 0b000011000;

                            inst[3][0] = '0';
                            istringstream(inst[3]) >> valor;
                            valor &= 0b001111000000;

                            //colocando o restante dos bits com o op(0) já que é a primeira instrução da linha
                            valor |= 0b00000 << 11;
                            printf("%x\n", valor);
                        }
                        else
                        {
                            int reg = 0;
                            reg = inst[1][1] - 48;
                            valor |= reg << 2;
                            valor &= 0b0011;

                            reg = inst[2][1] - 48;
                            valor |= reg << 5;
                            valor &= 0b00011000;

                            valor |= 0b0100000010 << 6;
                            printf("%x\n", valor);
                        }
                    }
                }
            }
            else if (inst[0] == "LSR") //linha 1
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    { //identificou a instrução ASR da 5º linha da tabela
                        if (inst[3][0] == '#')
                        {
                            ///rd
                            int reg = 0;
                            reg = inst[1][1] - 48;
                            valor |= reg << 2;
                            valor &= 0b0011;

                            //rn
                            reg = inst[2][1] - 48;
                            valor |= reg << 5;
                            valor &= 0b000011000;

                            inst[3][0] = '0';
                            istringstream(inst[3]) >> valor;
                            valor &= 0b001111000000;

                            //colocando o restante dos bits com o op(0) já que é a primeira instrução da linha
                            valor |= 0b00001 << 11;
                            printf("%x\n", valor);
                        }
                        else
                        {
                            int reg = 0;
                            reg = inst[1][1] - 48;
                            valor |= reg << 2;
                            valor &= 0b0011;

                            reg = inst[2][1] - 48;
                            valor |= reg << 5;
                            valor &= 0b00011000;

                            valor |= 0b0100000011 << 6;
                            printf("%x\n", valor);
                        }
                    }
                }
            }
            else if (inst[0] == "STR") //linha 22
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    { //identificou a instrução ASR da 5º linha da tabela
                        if (inst[3][0] == '#')
                        {
                            //rd
                            int reg = 0;
                            reg = inst[1][1] - 48;
                            valor |= reg << 2;
                            valor &= 0b0011;

                            //rn
                            reg = inst[2][1] - 48;
                            valor |= reg << 5;
                            valor &= 0b000011000;

                            inst[3][0] = '0';
                            istringstream(inst[3]) >> valor;
                            valor &= 0b001111000000;

                            valor |= 0b01100 << 11;
                            printf("%x\n", valor);
                        }
                        else if (inst[3][0] == 'R')
                        {
                            int reg1 = 0;
                            reg1 = inst[1][1] - 48;
                            valor |= reg1 << 0;
                            valor &= 0b0000000000000111;

                            int reg2 = 0;
                            reg2 = inst[2][1] - 48;
                            valor |= reg2 << 3;
                            valor &= 0b0000000000111111;

                            int reg3 = 0;
                            reg3 = inst[3][1] - 48;
                            valor |= reg3 << 6;
                            valor &= 0b0000000111111111;

                            //colocando o restante dos bits com o op(0) já que é a primeira instrução da linha
                            valor |= 0b0101000 << 9;
                            printf("%x\n", valor);
                        }
                    }
                }
            }
            else if (inst[0] == "LDR") //linha 22
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        if (inst[3][0] == '#')
                        {
                            //rd
                            int reg = 0;
                            reg = inst[1][1] - 48;
                            valor |= reg << 2;
                            valor &= 0b0011;

                            //rn
                            reg = inst[2][1] - 48;
                            valor |= reg << 5;
                            valor &= 0b000011000;

                            inst[3][0] = '0';
                            istringstream(inst[3]) >> valor;
                            valor &= 0b001111000000;

                            valor |= 0b01101 << 11;
                            printf("%x\n", valor);
                        }
                    }
                    else if (inst[2][0] == 'P')
                    {
                        if (inst[3][0] == '#')
                        {
                            inst[2][0] = '0';
                            istringstream(inst[2]) >> valor;
                            valor &= 0b0000000001111111;

                            int reg = 0;
                            reg = inst[1][1] - 48;
                            valor |= reg << 10;
                            valor &= 0b001100000000;

                            valor |= 0b01001 << 11;
                            printf("%x\n", valor);
                        }
                    }
                }
            }
            else if (inst[0] == "STRB") //linha 23
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    { //identificou a instrução ASR da 5º linha da tabela
                        if (inst[3][0] == '#')
                        {
                            //rd
                            int reg = 0;
                            reg = inst[1][1] - 48;
                            valor |= reg << 2;
                            valor &= 0b0011;

                            //rn
                            reg = inst[2][1] - 48;
                            valor |= reg << 5;
                            valor &= 0b000011000;

                            inst[3][0] = '0';
                            istringstream(inst[3]) >> valor;
                            valor &= 0b001111000000;

                            valor |= 0b01110 << 11;
                            printf("%x\n", valor);
                        }
                        else if (inst[3][0] == 'R')
                        {
                            int reg1 = 0;
                            reg1 = inst[1][1] - 48;
                            valor |= reg1 << 0;
                            valor &= 0b0000000000000111;

                            int reg2 = 0;
                            reg2 = inst[2][1] - 48;
                            valor |= reg2 << 3;
                            valor &= 0b0000000000111111;

                            int reg3 = 0;
                            reg3 = inst[3][1] - 48;
                            valor |= reg3 << 6;
                            valor &= 0b0000000111111111;

                            valor |= 0b0101010 << 9;
                            printf("%x\n", valor);
                        }
                    }
                }
            }
            else if (inst[0] == "LDRB") //linha 23
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    { //identificou a instrução ASR da 5º linha da tabela
                        if (inst[3][0] == '#')
                        {
                            //rd
                            int reg = 0;
                            reg = inst[1][1] - 48;
                            valor |= reg << 2;
                            valor &= 0b0011;

                            //rn
                            reg = inst[2][1] - 48;
                            valor |= reg << 5;
                            valor &= 0b000011000;

                            inst[3][0] = '0';
                            istringstream(inst[3]) >> valor;
                            valor &= 0b001111000000;

                            valor |= 0b01111 << 11;
                            printf("%x\n", valor);
                        }
                    }
                }
            }
            else if (inst[0] == "STRH") //linha 24
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        if (inst[3][0] == '#')
                        {
                            //rd
                            int reg = 0;
                            reg = inst[1][1] - 48;
                            valor |= reg << 2;
                            valor &= 0b0011;

                            //rn
                            reg = inst[2][1] - 48;
                            valor |= reg << 5;
                            valor &= 0b000011000;

                            inst[3][0] = '0';
                            istringstream(inst[3]) >> valor;
                            valor &= 0b001111000000;

                            valor |= 0b10000 << 11;
                            printf("%x\n", valor);
                        }
                        else if (inst[3][0] == 'R')
                        {
                            int reg1 = 0;
                            reg1 = inst[1][1] - 48;
                            valor |= reg1 << 0;
                            valor &= 0b0000000000000111;

                            int reg2 = 0;
                            reg2 = inst[2][1] - 48;
                            valor |= reg2 << 3;
                            valor &= 0b0000000000111111;

                            int reg3 = 0;
                            reg3 = inst[3][1] - 48;
                            valor |= reg3 << 6;
                            valor &= 0b0000000111111111;

                            valor |= 0b0101001 << 9;
                            printf("%x\n", valor);
                        }
                    }
                }
            }
            else if (inst[0] == "LDRH") //linha 24
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        if (inst[3][0] == '#')
                        {
                            //rd
                            int reg = 0;
                            reg = inst[1][1] - 48;
                            valor |= reg << 2;
                            valor &= 0b0011;

                            //rn
                            reg = inst[2][1] - 48;
                            valor |= reg << 5;
                            valor &= 0b000011000;

                            inst[3][0] = '0';
                            istringstream(inst[3]) >> valor;
                            valor &= 0b001111000000;

                            valor |= 0b10001 << 11;
                            printf("%x\n", valor);
                        }
                    }
                }
            }
            else if (inst[0] == "BX") //linha 18
            {
                if (inst[1][0] == 'R' || inst[1][0] == 'L')
                {
                    valor |= 0b000 << 2;

                    int reg = 0;
                    reg = inst[1][1] - 48;
                    valor |= reg << 8;
                    valor &= 0b00111000;

                    valor |= 0b010001110 << 7;
                    printf("%x\n", valor);
                }
            }
            else if (inst[0] == "BLX") //linha 18
            {
                if (inst[1][0] == 'R' || inst[1][0] == 'L')
                {
                    valor |= 0b000 << 2;

                    int reg = 0;
                    reg = inst[1][1] - 48;
                    valor |= reg << 8;
                    valor &= 0b00111000;

                    valor |= 0b010001111 << 7;
                    printf("%x\n", valor);
                }
            }
            else if (inst[0] == "LDRSB")
            { //Linha 20 da tabela opção 11
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        if (inst[3][0] == 'R')
                        {
                            int reg1 = 0;
                            reg1 = inst[1][1] - 48;
                            valor |= reg1 << 0;
                            valor &= 0b0000000000000111;

                            int reg2 = 0;
                            reg2 = inst[2][1] - 48;
                            valor |= reg2 << 3;
                            valor &= 0b0000000000111111;

                            int reg3 = 0;
                            reg3 = inst[3][1] - 48;
                            valor |= reg3 << 6;
                            valor &= 0b0000000111111111;

                            valor |= 0b0101011 << 9;
                            printf("%x\n", valor);
                        }
                    }
                }
            }
            //
            else if (inst[0] == "AND") //linha 7
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        reg = inst[2][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        valor |= 0b0100000000 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "EOR") //linha 7
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        reg = inst[2][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        valor |= 0b0100000001 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "ADC") //linha 8
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        reg = inst[2][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        valor |= 0b0100000101 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "SBC") //linha 8
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        reg = inst[2][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        valor |= 0b0100000110 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "ROR") //linha 8
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        reg = inst[2][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        valor |= 0b0100000111 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "TST") //linha 9
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        reg = inst[2][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        valor |= 0b0100001000 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "NEG") //linha 9
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        reg = inst[2][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        valor |= 0b0100001001 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "CMN") //linha 9
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        reg = inst[2][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        valor |= 0b0100001011 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "ORR") //linha 10
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        reg = inst[2][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        valor |= 0b0100001100 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "MUL") //linha 10
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        reg = inst[2][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        valor |= 0b0100001101 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "BIC") //linha 10
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        reg = inst[2][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        valor |= 0b0100001110 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "MVN") //linha 10
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        reg = inst[2][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        valor |= 0b0100001111 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "CPY") //linha 11
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        reg = inst[2][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        valor |= 0b0100011000 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            //
            else if (inst[0] == "SXTH") //linha 30
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        reg = inst[2][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        valor |= 0b1011001000 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "SXTB") //linha 30
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        reg = inst[2][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        valor |= 0b1011001001 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "UXTH") //linha 30
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        reg = inst[2][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        valor |= 0b1011001010 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "UXTB") //linha 30
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        reg = inst[2][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        valor |= 0b1011001011 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "REV") //linha 31
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        reg = inst[2][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        valor |= 0b1011101000 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "REV16") //linha 31
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        reg = inst[2][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        valor |= 0b1011101001 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "REVSH") //linha 31
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        reg = inst[2][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        valor |= 0b1011101010 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "SETEND LE") //linha 33
            {
                valor |= 0b1011011001010000 << 0;
                printf("%x\n", valor);
            }
            else if (inst[0] == "SETEND BE") //linha 33
            {
                valor |= 0b1011011001011000 << 0;
                printf("%x\n", valor);
            }
            else if (inst[0] == "BKPT") //linha 35
            {
                if (inst[1][0] == '#')
                {
                    inst[1][0] = '0';
                    istringstream(inst[1]) >> valor;
                    valor &= 0b01111111;

                    valor |= 0b10111110 << 8;
                    printf("%x\n", valor);
                }
            }
            else if (inst[0] == "SWI") //linha 35
            {
                if (inst[1][0] == '#')
                {
                    inst[1][0] = '0';
                    istringstream(inst[1]) >> valor;
                    valor &= 0b01111111;

                    valor |= 0b11011111 << 8;
                    printf("%x\n", valor);
                }
            }
            else if (inst[0] == "MVN")
            { //linha 10
                valor = 0;
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
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
            // problemas p/ identificar as instruções (reg alto e/ou baixo)
            // corrigir
            /* 
            else if (inst[0] == "ADD") //linha 12
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        reg = inst[2][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        valor |= 0b0100010001 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "MOV") //linha 12
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        reg = inst[2][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        valor |= 0b0100011001 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "ADD") //linha 13
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        reg = inst[2][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        valor |= 0b0100010010 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "MOV") //linha 13
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        reg = inst[2][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        valor |= 0b0100011010 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "ADD") //linha 14
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        reg = inst[2][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        valor |= 0b0100010011 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "MOV") //linha 14
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        reg = inst[2][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        valor |= 0b0100011011 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            */
            /*
            else if (inst[0] == "CMP") //linha 15
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        reg = inst[2][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        valor |= 0b0100010101 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "CMP") //linha 16
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        reg = inst[2][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        valor |= 0b0100010110 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            else if (inst[0] == "CMP") //linha 17
            {
                if (inst[1][0] == 'R')
                {
                    if (inst[2][0] == 'R')
                    {
                        int reg = 0;
                        reg = inst[1][1] - 48;
                        valor |= reg << 5;
                        valor &= 0b00011000;

                        reg = inst[2][1] - 48;
                        valor |= reg << 2;
                        valor &= 0b0011;

                        valor |= 0b0100010111 << 6;
                        printf("%x\n", valor);
                    }
                }
            }
            */
        }
    }
    in.close();
}

int main()
{
    decode();
    return 0;
}
