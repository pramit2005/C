#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node *next;
    int data;
}QNode;
typedef struct Q{
    QNode *front;
    QNode *rear;
}Queue;
QNode *createNode(int x){
    QNode *Q=(QNode*)malloc(sizeof(QNode));
    if(Q==NULL)
        return NULL;
    Q->data=x;
    Q->next=NULL;
    return Q;
}
void Enqueue(Queue *q,int data){
    QNode *newnode=createNode(data);
    if(newnode==NULL){
        printf("\n Memory allocation failed");
        return;
    }
    if(q->rear==NULL)
        q->rear=q->front=newnode;
    else{
        q->rear->next=newnode;
        q->rear=newnode;
    }
}
void Dequeue(Queue *q){
    if(q->rear==NULL){
        printf("\n Queue is empty");
        return;
    }
    else if(q->front->next==NULL){
        printf("\n %d",q->front->data);
        QNode *temp=q->front;
        q->front=NULL;
        q->rear=NULL;
        free(temp);
    }
    else{
        QNode *temp=q->front;
        q->front=q->front->next;
        printf("\n %d",temp->data);
        temp->next=NULL;
        free(temp);
    }
}
void Display(Queue *q){
    if(q->rear==NULL){
        printf("\n Queue is empty");
        return;
    }
    QNode *temp=q->front;
    while(temp){
        printf(" %d ",temp->data);
        temp=temp->next;
    }
}
int main(){
    Queue Q={NULL,NULL};
    int a,x;
    while(1){
    printf("\n 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit");
    printf("\n Enter a option: ");
    scanf("%d",&a);
    switch(a){
        case 1:
        printf("\n Enter a number: ");
        scanf("%d",&x);
        Enqueue(&Q,x);
        break;
        case 2:
        Dequeue(&Q);
        break;
        case 3:
        Display(&Q);
        break;
        case 4:
        exit(0);
        break;
        default:
        printf("\n Invalid option");
        break;
        }
    }
return 0;
}