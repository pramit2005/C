#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main()
{
    struct node *head=NULL;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=55;
    while(temp!=NULL){
        printf(" %d ",temp->data);
        temp=temp->next;
    }
}
