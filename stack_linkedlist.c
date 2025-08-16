#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* top=NULL;
void push(){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n Enter the number: ");
    scanf("%d",&newnode->data);
    if(top==NULL){
        top=newnode;
        top->next=NULL;
    }
    else{
        newnode->next=top;
        top=newnode;
    }
}
void pull(){
    if(top==NULL)
    printf("\n Stack underflow");
    else{
        struct node*temp=top;
        top=top->next;
        printf("\n The pulled element is %d",temp->data);
        free(temp);
    }
}
void print_stack(){
    struct node*temp=top;
    if(top==NULL)
    printf("\n Stack underflow");
else{
    while(temp){
    printf(" %d ",temp->data);
    temp=temp->next;
}
}
}
int main(){
    int a;
    while(1){
    printf("\n 1.Push\n 2.Pull\n 3.Print the stack\n 4.Exit");
    printf("\n Enter a option:  ");
    scanf("%d",&a);
    switch(a){
        case 1:
        push();
        break;
        case 2:
        pull();
        break;
        case 3:
        print_stack();
        break;
        case 4:
        exit(0);
        break;
        default:
        printf("Invalid input");
        break;
    }
    }
    return 0;
}
