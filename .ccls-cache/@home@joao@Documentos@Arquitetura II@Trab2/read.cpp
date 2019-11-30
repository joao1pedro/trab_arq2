// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

int main () {
  string line;
  ifstream myfile ("in.s");

  regex add1("(add r(\\d), r(\\d), #(.*))");
  smatch m;
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      //cout << line << '\n';
        if(regex_search(line, m, add1))
            cout << line << '\n';
        
        
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}
