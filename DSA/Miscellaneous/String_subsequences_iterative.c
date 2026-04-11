#include<stdio.h>
#include<string.h>
#include<math.h>
#define max 100
void String_Subsequences_Iterative(char *s,int n){
    int total=1<<n;
    for(int x=0;x<total;x++){
        for(int i=0;i<n;i++){
            if(x & (1<<i))
                printf("%c",s[i]);
        }
        /* printf("\n"); */
    }
}
int main(){
    char str[max];
    printf("\n Enter the string: ");
    fgets(str,sizeof(str),stdin);
    String_Subsequences_Iterative(str,strlen(str));
    return 0;
}
