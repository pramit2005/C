#include<stdio.h>
#include<stdlib.h>
struct ListNode {
      int val;
      struct ListNode *next;
  };
void printLL(struct ListNode *head){
    struct ListNode* temp=head;
    while(temp){
    printf("%d->",temp->val);
    temp=temp->next;
    }
    printf("NULL");
}
struct ListNode* insert(struct ListNode* head,int n){
    struct ListNode *temp=head;
    struct ListNode *newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val=n;
    newnode->next=NULL;
    if(head==NULL){
    head=newnode;
    }
    else{
    while(temp->next)
    temp=temp->next;
    temp->next=newnode;
    }
    return head;
}
struct ListNode* delete(struct ListNode* head){
    struct ListNode*temp=head;
    if(head==NULL){
        printf("\n Nothing to delete");
    }
    else if(head->next==NULL){
        head=NULL;
        free(temp);
    }
    else{
        while(temp->next->next)
        temp=temp->next;
        free(temp->next);
        temp->next=NULL;
    }
    return head;
}
struct ListNode* swapPairs(struct ListNode* head) {
    if(!head)
        return NULL;
    struct ListNode *temp=head,*Next=head->next,*prev=NULL;
    while(temp->next!=NULL){
        temp->next=Next->next;
        Next->next=temp;
        if(prev!=NULL)
            prev->next=Next;;
        if(head==temp)
            head=Next;
        if(temp->next!=NULL){
            Next=temp->next->next;
            prev=temp;
            temp=temp->next;
        }
        else
            break;
    }
    return head;
}
int main(){
    struct ListNode* head=NULL;
    int a,n;
    while(1){
        printf("\n 1.Insert\n 2.Delete\n 3.Print\n 4.Swap-pairs\n 5.Exit");
        printf("\n Enter a option: ");
        scanf("%d",&a);
        switch(a){
            case 1:
            printf("\n Enter the val: ");
            scanf("%d",&n);
            head=insert(head,n);
            break;
            case 2:
            head=delete(head);
            break;
            case 3:
            printLL(head);
            break;
            case 4:
            head=swapPairs(head);
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