#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* top=NULL;
void push(struct node **top,int n){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    if(*top==NULL){
        *top=newnode;
        (*top)->next=NULL;
    }
    else{
        newnode->next=*top;
        *top=newnode;
    }
}
int pop(struct node **top){
    int a;
    if(*top==NULL){
    printf("\n Stack underflow");
    return -1;
    }
    else{
        struct node*temp=*top;
        *top=(*top)->next;
        a=temp->data;
        temp->next=NULL;
        free(temp);
        return a;
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
int IsEmpty(struct node *top){
    return (top==NULL);
}
void Reverse_stack(struct node **top){
    struct node *top1=NULL,*top2=NULL;
    while(!IsEmpty(*top)){
        push(&top1,pop(top));
    }
    while(!IsEmpty(top1)){
        push(&top2,pop(&top1));
    }
    while(!IsEmpty(top2)){
        push(top,pop(&top2));
    }
}

int main(){
    int a,x;
    while(1){
    printf("\n 1.Push\n 2.pop\n 3.Print the stack\n 4.Reverse the stack\n 5.Exit");
    printf("\n Enter a option:  ");
    scanf("%d",&a);
    switch(a){
        case 1:
        printf("\n Enter a num: ");
        scanf("%d",&x);
        push(&top,x);
        break;
        case 2:
        x=pop(&top);
        printf(" %d ",x);
        break;
        case 3:
        print_stack(top);
        break;
        case 4:
        Reverse_stack(&top);
        break;
        case 5:
        exit(0);
        break;
        default:
        printf("Invalid input");
        break;
    }
    }
    return 0;
}
