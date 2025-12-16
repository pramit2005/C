#include<stdio.h>
#include<string.h>
char stack[10000];
int AreYouThere(char *s,char c,int left,int right){
    int flag=0;
    for(int i=left;i<=right;i++){
        if(c==s[i])
            flag=1;
    }
    return flag;
}
int DoYouExist(char *s,char c,int st){
    int k=st,flag=0;
    while(s[k]!='\0'){
        if(c==s[k])
            flag=1;
        k++;
    }
    return flag;
}
char* removeDuplicateLetters(char* s) {
    int top=-1,i=0;
    char ch;
    while(s[i]!='\0'){
        ch=s[i];
        if(top==-1){
            stack[++top]=s[i];
        }   
        else if((int)(stack[top])<=(int)(ch)){
            if(!AreYouThere(stack,ch,0,top))
                stack[++top]=ch;
        }
        else{
            if(!AreYouThere(stack,ch,0,top)){
                if(!DoYouExist(s,stack[top],i+1))
                    stack[++top]=ch;
                else{
                    while(top!=-1 && ((int)stack[top]>(int)ch) && DoYouExist(s,stack[top],i+1))
                        top--;
                    stack[++top]=ch;
                    }
                }
            } 
        i++;
    }
    stack[++top]='\0';
    return stack;
} 
int main(){
    char s[10000],*output;
    printf("\n Enter the string: ");
    fgets(s,sizeof(s),stdin);
    s[strcspn(s,"\n")]='\0';
    output=removeDuplicateLetters(s);
    puts(output);
    return 0;
}