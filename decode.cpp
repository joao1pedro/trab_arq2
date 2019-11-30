#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include <bits/stdc++.h>

#define set(x, y) (x | (1 << y))
#define reset(x, y) (x & ~(1 << y))

using namespace std;

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

int main()
{
	string line;
	ifstream in("in.s");
	ofstream out;

	short valor = 0;

	if (in.is_open())
	{
		while (getline(in, line))
		{
			transform(line.begin(), line.end(), line.begin(), ::toupper); //tranforma tudo em maiúscula
			vector<string> inst = split(line, " ");
			out.open("out.txt");
			if (inst[0] == "MOV")
			{
				if (inst[1][0] == 'R')
				{
					if (inst[2][0] == '#')
					{   //identificou a instrução MOV da 5º linha da tabela
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
						out << valor << "\n";
					}
				}
			}
			else if (inst[0] == "CMP")
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
						out << valor << "\n";
					}
				}
			}
			else if (inst[0] == "ADD")
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
						out << valor << "\n";
					}
				}
			}
			else if (inst[0] == "SUB")
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
						out << valor << "\n";
					}
				}
			}
		}
	}

	out.close();
	in.close();

	return 0;
}
