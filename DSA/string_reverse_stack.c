#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 30
    struct node{
        char data;
        struct node *next;
    };
struct node *top=NULL;
void push(char c){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=c;
    if(top==NULL){
        newnode->next=NULL;
        top=newnode;
    }
    else{
        newnode->next=top;
        top=newnode;
    }
}
char pop(){
    if(top==NULL){
        return '\0';
    }
    else{
        char x;
        x=top->data;
        struct node *temp=top;
        top=top->next;
        temp->next=NULL;
        free(temp);
        return x;
    }
}
int main(){
    char string[max],output[max];
    int i=0;
    printf("\n Enter the string: ");
    fgets(string,sizeof(string),stdin);
    while(string[i]!='\0'){
        push(string[i]);
        i++;
    }
    for(int j=0;j<i;j++){
        output[j]=pop();
    }
    output[i]='\0';
    printf("The reversed string is:%s",output);
    return 0;
}