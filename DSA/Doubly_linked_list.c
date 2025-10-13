#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node *prev;
};
struct node* head=NULL,*tail=NULL;
void createnode(int n){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        newnode->prev=NULL;
    } else {
           newnode->prev=tail;
           tail->next=newnode;
    }
    tail=newnode;
}

void printLL(){
    struct node* temp=head;
    struct node *temp2=tail;
    printf("NULL->");
    while(temp){
    printf("%d->",temp->data);
    temp=temp->next;
    }
    printf("NULL\n");
     printf("NULL->");
    while(temp2){
    printf("%d->",temp2->data);
    temp2=temp2->prev;
    }
    printf("NULL\n");
}
void insert_begining(int n){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    if(head==NULL){
    newnode->next=NULL;
    newnode->prev=NULL;
    head=newnode;
    tail=newnode;
    }
    else{
    newnode->next=head;
    newnode->prev=NULL;
    head->prev=newnode;
    head=newnode;    
    }
}
void insert_end(int n){
    struct node* temp=tail;
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=NULL;
    if(head==NULL){
    newnode->prev=NULL;
    tail=newnode;
    head=newnode;
    }
    else{
   newnode->prev=tail;
   tail->next=newnode;
   tail=newnode;
    }
}
void insert_position(int x,int n){
    struct node*temp=head;
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    if(head==NULL){
    printf("INVALID OPTION");
    }
    else 
    {
    while(temp->data!=x)
    temp=temp->next;
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next->prev=newnode;
    temp->next=newnode;   
    }
    }
void delete_begining(){
    struct node*temp=head;
    if(head==NULL)
        printf("\n Nothing to delete");
    else {
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
}
void delete_end(){
    struct node*temp=tail;
    if(head==NULL)
        printf("\n Nothing to delete");
    else if(head->next==NULL){
        head=NULL;
        tail=NULL;
        free(temp);
    }
    else{
       tail=tail->prev;
       tail->next=NULL;
       temp->prev=NULL;
       free(temp);
    }
}
void delete_position(){
    struct node*temp=head;
    int x;
    if(head==NULL)
    printf("\n Nothing to delete");
    else if(head->next==NULL){
    head=NULL;
    tail=NULL;
    free(temp);
    }
    else{
        printf("\n Enter the data of the node you want to delete: ");
        scanf("%d",&x);
        while(temp->data!=x)
        temp=temp->next;
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        temp->next=NULL;
        temp->prev=NULL;
        free(temp);
    }
}
void reverse(struct node* curr) {
    if (curr == NULL)
        return;
    if (curr->next == NULL) {
        head = curr;   
        return;
    }
    reverse(curr->next);
    curr->next->next = curr;
    curr->next = NULL; 
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
    printf("\n 1.Insert at the begining\n 2.Insert at position\n 3.Insert at the end\n 4.Print the Linked List\n 5.Delete at the begining\n 6.Delete at the position\n 7.Delete at the end\n 8.Reverse\n 9.Exit");
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
        insert_position(y,k);
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
        delete_begining();
        break;
        case 6:
        delete_position();
        break;
        case 7:
        delete_end();
        break;
        case 8:
        reverse(head);
        break;
        case 9:
        exit(0);
        default:
        printf("Invalid input");
        break;
    }
    }
    return 0;
}