#include<stdio.h>
#include<string.h>
#define max 100
void Print_Reverse_String(char* str,int index,int size){
    if(index==size)
        return;
    Print_Reverse_String(str,index+1,size);
    printf("%c",str[index]);
}
int main(){
    char s[max];
    int n;
    printf("\n Enter a string: ");
    scanf("%[^\n]",s);
    n=strlen(s);
    Print_Reverse_String(s,0,n);
    return 0;
}