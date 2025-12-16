#include<stdio.h>
#define max 20
char tree[max];
void root(char i){
    if(tree[0]!='\0')
        printf("\n Root exists");
    else
        tree[0]=i;
}
void left(int p,char i){
    if(tree[p]=='\0')
        printf("\n Parent does not exists");
    else
        tree[2*p+1]=i;  
}
void right(int p,char i){
    if(tree[p]=='\0')
        printf("\n Parent does not exists");
    else
        tree[2*p+2]=i; 
}
void print(){
    for(int i=0;i<max;i++){
        if(tree[i]=='\0')
            printf(" * ");
        else
            printf(" %c ",tree[i]);
    }
}
int main(){
    root('A');
    left(0,'B');
    right(0,'C');
    left(1,'D');
    right(1,'E');
    right(4,'F');
    print();
}