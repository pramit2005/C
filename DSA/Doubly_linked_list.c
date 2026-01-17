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
    struct node *temp=head;
    if(head==NULL){
        printf("\n Nothing to delete");
        return;
    }
    while(temp){
        printf("%d->",temp->data);
        temp=temp->next;
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
void insert_any_position(int h, int pos)
{
    int count=1; //count should have started from 1
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    struct node*temp=head;
    newnode->data=h;
    if(head==NULL)
    {
        newnode->next=newnode->prev=NULL;
        head=tail=newnode;
    }
    else
    {
        if(pos==1) //This should have been pos==1
        {
            newnode->next=head;
            head->prev=newnode;
            newnode->prev=NULL;
            head=newnode;
        }
        else
        {
            while(count<(pos-1) && temp->next!=NULL)
            {
                temp=temp->next;
                count++;
            }
            newnode->next=temp->next;
            newnode->prev=temp;
            if(temp->next!=NULL) //This should have been temp->next!=NULL 
                temp->next->prev=newnode;
            temp->next=newnode;
            if(temp==tail)
                tail==newnode;
        }
    }
}
void deletion_at_beg()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("no node found");
    }
    else if(head->next==NULL) //This should have been head->next==NULL
    {
        temp=head;
        head=tail=NULL;
        free(temp);
    }
    else
    {
        temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        free(temp);
    }
}
void deletion_at_end()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("no node found");
    }
    else if(head->next==NULL) //This should have been head->next!=NULL
    {
        temp=head;
        head=tail=NULL;
        free(temp);
    }
    else
    {
        temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        temp->prev=NULL;
        free(temp);
    }
}
void deletion_at_any_pos(int pos)
{
   struct node*temp=head;//temp was never initialized
   int count=1;//Count should have been started from 1
    if(head==NULL)
    {
        printf("no node found");
    }
    else if(head->next==NULL)
    {
        temp=head;
        head=tail=NULL;
        free(temp);
    }
    else 
    {
        if(pos==1) //It should have been pos==1 
        {
            deletion_at_beg();
            return;
        }   //We should check pos==1 before traversing,if it is true then there is no need to traverse & therefore no need to check temp==head
        while(count<pos && temp->next!=NULL)
        {
            temp=temp->next;
            count++;
        }
        if(temp==tail)//So,I changed 'else if' to 'if'
        {
           deletion_at_end();
           return; 
        }
        else
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            temp->next=NULL;
            temp->prev=NULL;
            free(temp);
        }
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
        printf("\n Enter the position of the node to add: ");
        scanf("%d",&y);
        printf("\n Enter the data of the node: ");
        scanf("%d",&k);
        insert_any_position(k,y);
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
        deletion_at_beg();
        break;
        case 6:
        printf("\n Enter the position of the node to delete: ");
        scanf("%d",&y);
        deletion_at_any_pos(y);
        break;
        case 7:
        deletion_at_end();
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
