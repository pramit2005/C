#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
void createnode(int n){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=NULL;
    if(head==NULL)
    head=newnode;
    else
    {
    struct node* temp=head;
    while(temp->next)
    temp=temp->next;
    temp->next=newnode;    
    }
}
void printLL(){
    struct node* temp=head;
    while(temp){
    printf("%d->",temp->data);
    temp=temp->next;
    }
    printf("NULL");
}
int length(){
    int count=0;
    struct node *temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
int main(){
    int m,x;
    printf("\n Enter the number of nodes of the linked list: ");
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        printf("\n Enter the element of %d node:  ",i);
        scanf("%d",&x);
        createnode(x);
    }
    printLL();
    printf("\n The size of the linked-list is:%d",length());
    return 0;
}