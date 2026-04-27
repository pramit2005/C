#include<stdio.h>
#define max 100
void String_Subsequences(char *str,int index,char *curr,int curr_index){
    if(str[index]=='\0'){
        curr[curr_index]='\0';
        printf("%s\n",curr);
        return;
    }
    curr[curr_index]=str[index];
    String_Subsequences(str,index+1,curr,curr_index+1);     //Including current character
    String_Subsequences(str,index+1,curr,curr_index);       //Excluding current character
}
int main(){
    char s[max],current[max];
    printf("\n Enter the string to find subsequences: ");
    scanf("%[^\n]",&s);
    String_Subsequences(s,0,current,0);
    return 0;
}