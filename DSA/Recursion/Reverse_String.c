#include<stdio.h>
#include<string.h>
#define max 100
void Reverse_String(char* str,int low,int high){    //Linear Recursion
    if(low>=high)
        return;
    char temp=str[low];
    str[low]=str[high];
    str[high]=temp;
    Reverse_String(str,low+1,high-1);
}

int main(){
    char s[max];
    int n;
    printf("\n Enter a string: ");
    scanf("%[^\n]",s);
    n=strlen(s);
    Reverse_String(s,0,n-1);
    printf("%s",s);
    return 0;
}
