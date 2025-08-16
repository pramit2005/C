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
void delete_begining(){
    struct node*temp=head;
    if(head==NULL)
        printf("\n Nothing to delete");
    else {
        head=head->next;
        free(temp);
    }
}
void delete_end(){
    struct node*temp=head;
    if(head==NULL || head->next==NULL)
        printf("\n Nothing to delete");
    else{
        while(temp->next->next)
        temp=temp->next;
        free(temp->next);
        temp->next=NULL;
    }
}
void delete_middle(){
    struct node*temp=head;
    int x;
     if(head==NULL || head->next==NULL)
        printf("\n Nothing to delete");
    else{
        printf("\n Enter the data of the node you want to delete: ");
        scanf("%d",&x);
        while(temp->next->data!=x)
        temp=temp->next;
        struct node*temp2=temp->next;
        temp->next=temp->next->next;
        free(temp2);
    }
}
int main(){
    int m,x,a;
    printf("\n Enter the number of nodes of the linked list: ");
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        printf("\n Enter the element of %d node:  ",i);
        scanf("%d",&x);
        createnode(x);
    }
    while(1){
        int k=0;
    printf("\n 1.Delete at the begining\n 2.Delete at the middle\n 3.Delete at the end\n 4.Print the Linked List\n 5.Exit");
    printf("\n Enter a option:  ");
    scanf("%d",&a);
    switch(a){
        case 1:
        delete_begining();
        break;
        case 2:
        delete_middle();
        break;
        case 3:
        delete_end();
        break;
        case 4:
        printLL();
        break;
        case 5:
        exit(0);
        break;
        default:
        printf("\n Invalid option");
        break;
    }
}

    return 0;
}