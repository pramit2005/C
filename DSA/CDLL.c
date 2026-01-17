#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *tail=NULL;
void createNode(int x){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    if(tail==NULL){
        newnode->next=newnode->prev=newnode;
        tail=newnode;
    }
    else{
        newnode->next=tail->next;
        tail->next->prev=newnode;
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}
void insert_beginning(int x){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    if(tail==NULL){
        newnode->next=newnode->prev=newnode;
        tail=newnode;
    }
    else{
        newnode->next=tail->next;
        newnode->prev=tail;
        tail->next->prev=newnode;
        tail->next=newnode;
    }
}
void insert_end(int x){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    if(tail==NULL){
        newnode->next=newnode->prev=newnode;
        tail=newnode;
    }
    else{
        newnode->next=tail->next;
        tail->next->prev=newnode;
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}
void insert_at_position(int pos,int x){
    int count=1;
    struct node *temp;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    if(tail==NULL){
        newnode->next=newnode->prev=newnode;
        tail=newnode;
        return;
    }
    if(pos==1){
        insert_beginning(x);
        return;
    }
    temp=tail->next;
    while(count<pos-1 && temp->next!=tail->next){
        count++;
        temp=temp->next;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next->prev=newnode;
    temp->next=newnode;
    if(temp==tail)
    tail=newnode;
}
void delete_beginning(){
    struct node *temp;
    if(tail==NULL)
        printf("\n No node to delete");
    else if(tail==tail->next){
        temp=tail;
        tail->next=tail->prev=NULL;
        tail=NULL;
        free(temp);
    }
    else{
        temp=tail->next;
        tail->next=temp->next;
        temp->next->prev=tail;
        temp->next=temp->prev=NULL;
        free(temp);
    }
}
void delete_end(){
    struct node *temp;
    if(tail==NULL)
        printf("\n No node to delete");
    else if(tail==tail->next){
        temp=tail;
        tail->next=tail->prev=NULL;
        tail=NULL;
        free(temp);
    }
    else{
        temp=tail;
        tail->prev->next=tail->next;
        tail->next->prev=tail->prev;
        tail=tail->prev;
        temp->next=temp->prev=NULL;
        free(temp);
    }
}
void delete_at_position(int pos){
    int count=1;
    struct node *temp;
    if(tail==NULL){
        printf("\n No node to delete");
        return;
    }
    else if(tail==tail->next){
        temp=tail;
        tail->next=tail->prev=NULL;
        tail=NULL;
        free(temp);
    }
    else{
        if(pos==1){
            delete_beginning();
            return;
        }
        temp=tail->next;
        while(count<pos && temp->next!=tail->next){
            count++;
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        if(temp==tail)
        tail=tail->prev;
        temp->next=temp->prev=NULL;
        free(temp);
    }
}
void display(){
    if(tail==NULL)
        printf("\n The linked list is empty");
    else{
        struct node *temp=tail->next;
        do{
            printf("->%d-",temp->data);
            temp=temp->next;
        }while(temp!=tail->next);
    }
}
int main(){
    int m,x,a,y;
    printf("\n Enter the number of nodes of the linked list: ");
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        printf("\n Enter the element of %d node:  ",i);
        scanf("%d",&x);
        createNode(x);
    }
    while(1){
        int k=0;
    printf("\n 1.Insert at the begining\n 2.Insert at the position\n 3.Insert at the end\n 4.Print the Linked List\n 5.Delete at the begining\n 6.Delete at the position\n 7.Delete at the end\n 8.Exit");
    printf("\n Enter a option:  ");
    scanf("%d",&a);
    switch(a){
        case 1:
        printf("\n Enter the data of the node: ");
        scanf("%d",&k);
        insert_beginning(k);
        break;
        case 2:
        printf("\n Enter the position of the node to add: ");
        scanf("%d",&y);
        printf("\n Enter the data of the node: ");
        scanf("%d",&k);
        insert_at_position(y,k);
        break;
        case 3:
         printf("\n Enter the data of the node: ");
        scanf("%d",&k);
        insert_end(k);
        break;
        case 4:
        display();
        break;
         case 5:
        delete_beginning();
        break;
        case 6:
        printf("\n Enter the position of the node to delete: ");
        scanf("%d",&y);
        delete_at_position(y);
        break;
        case 7:
        delete_end();
        break;
        case 8:
        exit(0);
        break;
        default:
        printf("Invalid input");
        break;
    }
    }
    return 0;
}