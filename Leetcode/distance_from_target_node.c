#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode {
      int val;
      struct TreeNode *left;
     struct TreeNode *right;
}Tree;
typedef struct queue_node{
    struct queue_node*next;
    Tree *ptr;
}QNode;
typedef struct Q{
    QNode *front;
    QNode *rear;
}Queue;
QNode* createNode(Tree *p){
    QNode *Q=(QNode*)malloc(sizeof(QNode));
    if(Q==NULL)
        return NULL;
    Q->ptr=p;
    Q->next=NULL;
    return Q;
}
void Enqueue(Queue *q,Tree *p){
    QNode *newnode=createNode(p);
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
Tree* Dequeue(Queue *q){
    if(q->rear==NULL){
        printf("\n Queue is empty");
        return NULL;
    }
    else if(q->front->next==NULL){
        Tree *temp_ptr=q->front->ptr;
        QNode *temp=q->front;
        q->front=NULL;
        q->rear=NULL;
        free(temp);
        return temp_ptr;
    }
    else{
        Tree *temp_ptr=q->front->ptr;
        QNode *temp=q->front;
        q->front=q->front->next;
        temp->next=NULL;
        free(temp);
        return temp_ptr;
    }
}
int IsEmpty(Queue *q){
    return (q->rear==NULL);
}
void Delete_Queue(Queue *q){
    if(q->rear==NULL)
        return;
    QNode *current=q->front;
    QNode *next_node;
    while(current){
        next_node=current->next;
        free(current);
        current=next_node;
    }
    q->front=NULL;
    q->rear=NULL;
}
int* distanceK(struct TreeNode* root, struct TreeNode* target, int k, int* returnSize) {
    //Need to find a way to consider distance from target node
    int count=0;
    if(root==NULL){
        *returnSize=count;
        return NULL;
    }
    Queue q={NULL,NULL};
    Tree *temp;
    Enqueue(&q,root);
    while(!IsEmpty(&q)){
        temp=Dequeue(&q);

    }
         
}