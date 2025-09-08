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
        tail=newnode;
        newnode->prev=NULL;
    } else {
         newnode->prev=tail;
         tail->next=newnode;
         tail=newnode;
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
     printf("NULL<-");
    while(temp2){
    printf("%d<-",temp2->data);
    temp2=temp2->prev;
    }
    printf("NULL\n");
}
void insertion_sort() {
    struct node *key,*temp;
    if (head == NULL) {
        printf("\nNo linked list to sort");
        return;
    }
    if (head->next == NULL) {
        printf("\nThe sorted linked list: %d", head->data);
        return;
    }

    struct node *sorted = NULL; 
    key = head;                  

    while (key != NULL) {
        struct node *next = key->next;
        key->prev = key->next = NULL;
        
        if (sorted == NULL || key->data < sorted->data) {
            key->next = sorted;
            if (sorted != NULL) {
                sorted->prev = key;
            }
            sorted = key;
        } else {
            temp = sorted;
            while (temp->next != NULL && temp->next->data < key->data) {
                temp = temp->next;
            }
            key->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = key;
            }
            temp->next = key;
            key->prev = temp;
        }

        key = next; 
    }
    head = sorted;
    tail = sorted;
    while (tail->next != NULL) {
        tail = tail->next;
    }
}

void bubble_sort() {
    if (head == NULL) {
        printf("\nNo linked list to sort");
        return;
    }
    if (head->next == NULL) {
        printf("\nThe sorted linked list: %d", head->data);
        return;
    }

    int swapped;
    struct node *ptr;
    struct node *last = NULL;

    do {
        swapped = 0;
        ptr = head;

        while (ptr->next != last) {
            if (ptr->data > ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        last = ptr; 
    } while (swapped);
}

void max(){
    if(head==NULL)
    printf("\nNo maximum");
    else if(head->next==NULL)
    printf("\nThe maximum is:%d",head->data);
    else{
        int max=head->data;
        struct node *temp=head->next;
        while(temp){
            if((temp->data)>max)
            max=temp->data;
        temp=temp->next;
        }
        printf("\n The maximum number of the linked list is: %d",max);
    }
}
void min(){
    if(head==NULL)
    printf("\nNo maximum");
    else if(head->next==NULL)
    printf("\nThe maximum is:%d",head->data);
    else{
        int min=head->data;
        struct node *temp=head->next;
        while(temp){
            if((temp->data)<min)
            min=temp->data;
        temp=temp->next;
        }
        printf("\n The minimum number of the linked list is: %d",min);
    }
}
void search(){
    int x;
    struct node *temp=head;
    printf("\n Enter the number to search: ");
    scanf("%d",&x);
    if(head==NULL)
    printf("\nNo linked list to search");
    else{
        int flag=0,count=0;
        while(temp){
            if(temp->data==x){
                flag=1;
                count++;
                break;
            }
                count++;
                temp=temp->next;
        }
        if(flag){
            printf("The number is found at node %d",count);
            return;
        }
        printf("Number not in the linked list");
    }
 }
 void count(){
    struct node *temp=head;
    if(head==NULL)
    printf("\n The number of nodes:0");
    else{
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        printf("\n The number of nodes:%d",count);
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
        printf("\n 1.Sort\n 2.Find maximum\n 3.Find minimum\n 4.Searching\n 5.Count number of nodes\n 6.Print the linked list\n 7.Exit");
        printf("\nEnter a option: ");
        scanf("%d",&a);
        switch(a){
            case 1:
            bubble_sort();
            printLL();
            break;
            case 2:
            max();
            break;
            case 3:
            min();
            break;
            case 4:
            search();
            break;
            case 5:
            count();
            break;
            case 6:
            printLL();
            break;
            case 7:
            exit(0);
            break;
            default:
            printf("Invalid option");
            break;
        }
    }
    return 0;
 }

