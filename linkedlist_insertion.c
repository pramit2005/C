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
    if(head==NULL){
    head=newnode;
    }
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
void insert_begining(int n){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    if(head==NULL){
    head=newnode;
    head->next=NULL;
    }
    else{
    newnode->next=head;
    head=newnode;    
    }
}
void insert_end(int n){
    struct node* temp=head;
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=NULL;
    if(head==NULL){
    head=newnode;
    }
    while(temp->next)
    temp=temp->next;
    temp->next=newnode;
}
void insert_middle(int x,int n){
    struct node*temp=head;
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=NULL;
    if(head==NULL){
    printf("INVALID OPTION");
    }
    else 
    {
        while(temp->data!=x)
        temp=temp->next;
        newnode->next=temp->next;
        temp->next=newnode;
    }
    }

int main(){
    int m,x,a,y;
    printf("\n Enter the number of nodes of the linked list: ");
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        printf("\n Enter the element of %d node:  ",i);
        scanf("%d",&x);
        createnode(x);
    }
    while(1){
        int k=0;
    printf("\n 1.Insert at the begining\n 2.Insert at the middle\n 3.Insert at the end\n 4.Print the Linked List\n 5.Exit");
    printf("\n Enter a option:  ");
    scanf("%d",&a);
    switch(a){
        case 1:
        printf("\n Enter the data of the node: ");
        scanf("%d",&k);
        insert_begining(k);
        break;
        case 2:
        printf("\n Enter the data of the node after which you want to add: ");
        scanf("%d",&y);
        printf("\n Enter the data of the node: ");
        scanf("%d",&k);
        insert_middle(y,k);
        break;
        case 3:
         printf("\n Enter the data of the node: ");
        scanf("%d",&k);
        insert_end(k);
        break;
        case 4:
        printLL();
        break;
        case 5:
        exit(0);
        default:
        printf("Invalid input");
        break;
    }
    }
    return 0;
}