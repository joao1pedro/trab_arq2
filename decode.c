#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc, char const *argv[])
{
    FILE* inp;
    inp = fopen("in.s","r");		//filename of your data file
    char arr[100][50];			//max word length 50
    int i = 0;
    while(1){
        char r = (char)fgetc(inp);
        int k = 0;
        while(r!=',' && !feof(inp)){	//read till , or EOF
            arr[i][k++] = r;			//store in array
            r = (char)fgetc(inp);
        }
        arr[i][k]=0;		//make last character of string null 
        if(feof(inp)){		//check again for EOF
            break;
        }
        i++;
    }
    int j;
    int counta = 0;
    int countb = 0;
    for(j = 0;j<=i;j++){
        //printf("%s",arr[j] );	//print array
        if(strcasestr(arr[j], "add"))
            counta++;
        if(strcasestr(arr[j], "bge"))
            countb++;
    }
    printf("number of instruction add: %d\n", counta);
    printf("number of instruction bge: %d\n", countb);
    return 0;
}
