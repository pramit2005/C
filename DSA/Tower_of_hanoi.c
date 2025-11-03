#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void push(struct node **top,int x){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    if(*top==NULL){
        newnode->next=NULL;
        *top=newnode;
    }
    else{
        newnode->next=*top;
        *top=newnode;
    }
}
int pop(struct node **top){
    if(*top==NULL)
        printf("\n The stack is empty");
        return -1;
    else{
        int n=top->data;
        struct node *temp=*top;
        *top=(*top)->next;
        free(temp);
        return n;
    }
}
void TowerOfHanoi(int n,struct node **from_top,struct node **to_top,struct node **aux_top){
    if(n==1){
        int x=pop(from_top);
        push(to_top,x);
        return;
    }
    TowerOfHanoi(n-1,from_top,aux_top,to_top);
    int x=pop(from_top);
        push(to_top,x);

    TowerOfHanoi(n-1,aux_top,to_top,from_top);
}

int main(){

}

