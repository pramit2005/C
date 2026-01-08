#include<stdio.h>
#include<stdlib.h>
struct ListNode {
      int val;
      struct ListNode *next;
  };
typedef struct node{
    struct ListNode *ptr;
    struct node *next;
}SNode;
typedef struct s{
    SNode *top;
}Stack;
SNode* createNode(struct ListNode *temp){
    SNode *newnode=(SNode*)malloc(sizeof(SNode));
    if(!newnode)
        return NULL;
    newnode->ptr=temp;
    newnode->next=NULL;
    return newnode;
}
void push(Stack *s,struct ListNode *temp){
    SNode *newnode=createNode(temp);
    if(!newnode)
        printf("\n Memory allocation failed");
    else{
        if(s->top==NULL)
            s->top=newnode;
        else{
            newnode->next=s->top;
            s->top=newnode;
        }
    }
}
struct ListNode* pop(Stack *s){
    if(s->top==NULL)
        return NULL;
    SNode *temp=s->top;
    struct ListNode *temp2=s->top->ptr;
    s->top=s->top->next;
    temp->next=NULL;
    free(temp);
    return temp2;
}
int IsEmpty(Stack *s){
    return s->top==NULL;
}
void printLL(struct ListNode *head){
    struct ListNode* temp=head;
    while(temp){
    printf("%d->",temp->val);
    temp=temp->next;
    }
    printf("NULL");
}
int AreThereEnough(struct ListNode *current,int k){
    int count=0;
    while(current){
        count++;
        current=current->next;
    }
    return count>=k;
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
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if(head==NULL || head->next==NULL)
        return head;
    Stack s={NULL};
    struct ListNode *temp_head=head,*k1,*temp,*prev=NULL;
    while(AreThereEnough(temp_head,k)){
        for(int i=0;i<k;i++){
            push(&s,temp_head);
            temp_head=temp_head->next;
        }
        k1=temp_head;
        while(!IsEmpty(&s)){
            temp=pop(&s);
            if(prev==NULL){
                head=temp;
                prev=temp;
            }
            else{
                prev->next=temp;
                prev=temp;
            }
        }
        temp->next=k1;
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
            head=reverseKGroup(head,3);
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