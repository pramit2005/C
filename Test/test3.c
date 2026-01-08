#include<stdio.h>
struct ListNode* swapPairs(struct ListNode* head) {
    if(!head)
        return NULL;
    struct ListNode* temp=head,*Next=head->next,*new,*prev=NULL;
    while(Next!=NULL){
        new=Next->next;
        Next->next=temp;
        temp->next=new;
        if(prev!=NULL)
            prev->next=Next;
        if(temp==head)
            head=Next;
        if(new==NULL)
            break;
        else{
            temp=new;
            prev=temp;
            Next=new->next;
        }
    }
    return head;
}
int main()
{
   
return 0;
}