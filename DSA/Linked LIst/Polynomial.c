#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int exp;
    struct node *next;
};
struct node* createNode(struct node *head,int co,int expo){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->coeff=co;
    newnode->exp=expo;
    if(head==NULL)
    head=newnode;
    else{
        struct node *temp=head;
        while(temp->next)
        temp=temp->next;
        temp->next=newnode;
    }
    return head;
}
struct node* insertion_sort(struct node *head){
    if(head==NULL || head->next==NULL)
    return head;
    struct node *sorted=NULL;
    struct node *current=head;
    struct node *Next;
    while(current!=NULL){
        Next=current->next;
        if(sorted==NULL || current->exp>sorted->exp){
            current->next=sorted;
            sorted=current;
        }
        else{
            struct node *temp=sorted;
            while(temp->next!=NULL && temp->next->exp>current->exp)
                temp=temp->next;
            current->next=temp->next;
            temp->next=current;
        }
        current=Next;
    }
    return sorted;
}
void print(struct node *head){
    if(head==NULL)
    printf("\n Nothing to print");
    else{
        head=insertion_sort(head);
        struct node *temp=head;
        while(temp){
            if(temp->coeff>0)
            printf("+%d_x^%d",temp->coeff,temp->exp);
            else
                printf("%d_x^%d",temp->coeff,temp->exp);
            temp=temp->next; 
        }
    }
}
struct node *add(struct node *head1,struct node *head2){
    head1=insertion_sort(head1);
    head2=insertion_sort(head2);
    struct node *temp1=head1;
    struct node *temp2=head2;
    struct node *head3=NULL;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->exp==temp2->exp){
            head3=createNode(head3,temp1->coeff+temp2->coeff,temp1->exp);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->exp>temp2->exp){
            head3=createNode(head3,temp1->coeff,temp1->exp);
            temp1=temp1->next;
        }
        else{
             head3=createNode(head3,temp2->coeff,temp2->exp);
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL){
        head3=createNode(head3,temp1->coeff,temp1->exp);
            temp1=temp1->next;
    }
    while(temp2!=NULL){
        head3=createNode(head3,temp2->coeff,temp2->exp);
            temp2=temp2->next;
    }
    return head3;
}
int main(){
    struct node *head1=NULL,*head2=NULL,*addition;
    int m,n,c,e,a,op;
    printf("Enter the number of terms of first equation: ");
    scanf("%d",&m);
    printf("Enter the number of terms of second equation: ");
    scanf("%d",&n);
    printf("\n Enter the first equation: ");
    for(int i=0;i<m;i++){
        printf("\n Enter the coefficient of term %d: ",i+1);
        scanf("%d",&c);
        printf("\n Enter the exponent of term %d: ",i+1);
        scanf("%d",&e);
        head1=createNode(head1,c,e);
    }
    printf("\n Enter the second equation: ");
    for(int i=0;i<n;i++){
        printf("\n Enter the coefficient of term %d: ",i+1);
        scanf("%d",&c);
        printf("\n Enter the exponent of term %d: ",i+1);
        scanf("%d",&e);
        head2=createNode(head2,c,e);
    }
    while(1){
         printf("\n 1.Display\n 2.Addition\n 3.Exit");
    printf("\n Enter a option: ");
    scanf("%d",&a);
    switch(a){
        case 1:
        printf("\n 1.Equation 1\n 2.Equation 2");
        printf("\n Enter a option: ");
        scanf("%d",&op);
        if(op==1)
        print(head1);
        else
        print(head2);
        break;
        case 2:
        addition=add(head1,head2);
        printf("\n The resultant equation is: ");
        print(addition);
        break;
        case 3:
        exit(0);
        break;
        default:
        printf("\n Invalid option");
        break;
    }
}
    return 0;
}