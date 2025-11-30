#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    int priority;
    struct node *next;
}QNode;
typedef struct Node{
    struct Node *front;
    struct Node *rear;
}Queue;
QNode* CreateNode(){
    QNode* newnode=(QNode*)malloc(sizeof(QNode));
    if(!newnode)
        return NULL;
    printf("\n Enter the data: ");
    scanf("%d",&newnode->data);
    printf("\n Enter the priority: ");
    scanf("%d",&newnode->priority);
    newnode->next=NULL;
    return newnode;
}
void Enqueue(Queue *q){
    QNode *newnode=CreateNode();
    if(q->rear==NULL){
        q->front=q->rear=newnode;
    }
    else{
        QNode *temp=q->front;
        if(q->front->)
        while((temp->next->priority)<=(newnode->priority))
            temp=temp->next;

    }
}
int Dequeue(){

}