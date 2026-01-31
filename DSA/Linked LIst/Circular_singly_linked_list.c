#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* tail=NULL;
void createnode(int n){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
   if(tail==NULL){
    tail=newnode;
    tail->next=tail;
   }
   else{
    newnode->next=tail->next;
    tail->next=newnode;
    tail=newnode;
   }
}
void printLL(){
    if(tail==NULL){
        printf("\n Nothing to delete");
        return;
    }
    struct node* temp=tail->next;
   do {
    printf("->%d-",temp->data);
    temp=temp->next;
   }while(temp!=tail->next);
}
void insert_begining(int n){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    if(tail==NULL){
    tail=newnode;
    tail->next=tail;
    }
    else{
    newnode->next=tail->next;
    tail->next=newnode;
    }
}
void insert_end(int n){
    struct node* temp=tail;
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    if(tail==NULL){
    tail=newnode;
    tail->next=tail;
    }
    else{
    newnode->next=tail->next;
    tail->next=newnode;
    tail=newnode;
    }
}
void insert_at_pos(int h,int pos)
{   int count=1;
    if(tail==NULL)
    {
        insert_begining(h);
        return;
    }
    else
    {
        if(pos==1)
        {
            insert_begining(h);
            return;
        }
        struct node*newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=h;
        struct node*temp=tail->next;
        while(count<pos-1 && temp->next!=tail->next)
        {
            count++;
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        if(temp==tail)
        {
            tail=newnode;
        }
    }
}
void delete_begining(){
    struct node*temp=tail->next;
    if(tail==NULL)
        printf("\n Nothing to delete");
    else if(tail->next==tail){
        tail=NULL;
        free(temp);
    }
    else {
        tail->next=tail->next->next;
        temp->next=NULL;
        free(temp);
    }
}
void delete_end(){
    struct node*temp=tail->next;
    if(tail==NULL)
        printf("\n Nothing to delete");
    else if(tail->next==tail){
        tail=NULL;
        free(temp);
    }
    else{
        while(temp->next!=tail)
        temp=temp->next;
        struct node *temp2=tail;
        temp->next=tail->next;
        tail=temp;
        temp2->next=NULL;
        free(temp2);
    }
}
void Deletion_at_pos(int pos)
{
    struct node*temp,*temp2;
    int count=1;
    if(tail==NULL)
    {
        printf("\n No node to delete");
    }
    else
    {
        if(pos==1)
        {
           delete_begining();
           return; 
        }
        else
        {
            temp=tail->next;
            while(count<pos-1 && temp->next!=tail)
            {
                temp=temp->next;
                count++;
            }
            temp2=temp->next;
            temp->next=temp2->next;
            temp2->next=NULL;
                if(temp2==tail)
                    tail=temp;
            free(temp2);
        }
}
}
void reverse(struct node* curr) {
    if (curr == NULL)
        return;
    if (curr->next == NULL) {
        tail = curr;   
        return;
    }
    reverse(curr->next);
    curr->next->next = curr;
    curr->next = NULL; 
}
void insertionSort() {
    if (tail == NULL || tail->next == tail) return;

    struct node* sorted = NULL;
    struct node* current = tail->next;
    struct node* next;
    tail->next = NULL;
    while (current != NULL) {
        next = current->next;
        if (sorted == NULL || current->data < sorted->data) {
            current->next = sorted;
            sorted = current;
        } else {
            struct node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    tail = sorted;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = sorted;
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
    printf("\n 1.Insert at the begining\n 2.Insert at the position\n 3.Insert at the end\n 4.Print the Linked List\n 5.Delete at the begining\n 6.Delete at the position\n 7.Delete at the end\n 8.Reverse");
    printf("\n 9.Sort\n 10.Exit");
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
        insert_at_pos(k,y);
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
        printf("\n Enter the position of the node to delete: ");
        scanf("%d",&y);
        Deletion_at_pos(y);
        break;
        case 7:
        delete_end();
        break;
        case 8:
        reverse(tail);
        break;
        case 9:
        insertionSort();
        break;
        case 10:
        exit(0);
        default:
        printf("Invalid input");
        break;
    }
    }
    return 0;
}