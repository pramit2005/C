#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
      int val;
      struct TreeNode *left;
     struct TreeNode *right;
};
typedef struct queue_node{
    struct queue_node*next;
    struct TreeNode *ptr;
}QNode;
typedef struct Q{
    QNode *front;
    QNode *rear;
}Queue;
QNode* createNode(struct TreeNode *p){
    QNode *Q=(QNode*)malloc(sizeof(QNode));
    if(Q==NULL)
        return NULL;
    Q->ptr=p;
    Q->next=NULL;
    return Q;
}
void Enqueue(Queue *q,struct TreeNode *p){
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
struct TreeNode* Dequeue(Queue *q){
    if(q->rear==NULL){
        printf("\n Queue is empty");
        return NULL;
    }
    else if(q->front->next==NULL){
        struct TreeNode *temp_ptr=q->front->ptr;
        QNode *temp=q->front;
        q->front=NULL;
        q->rear=NULL;
        free(temp);
        return temp_ptr;
    }
    else{
        struct TreeNode *temp_ptr=q->front->ptr;
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
void Root_Distance(struct TreeNode *root,int a[]){
    int h=0;
    if(!root)
        return;
    Queue q={NULL,NULL};
    struct TreeNode *temp;
    Enqueue(&q,root);
    Enqueue(&q,NULL);
    while(!IsEmpty(&q)){
        temp=Dequeue(&q);
        if(temp==NULL){
            if(!IsEmpty(&q))
                Enqueue(&q,NULL);
            h++;
        }
        else{
            a[temp->val]=h;
            if(temp->left)
                Enqueue(&q,temp->left);
            if(temp->right)
                Enqueue(&q,temp->right);
        }
    }
    Delete_Queue(&q);
}
int* distanceK(struct TreeNode* root, struct TreeNode* target, int k, int* returnSize) {
    int count=0;
    int hash[501];
    int *output=(int*)malloc(sizeof(int)*501);
    if(root==NULL){
        *returnSize=count;
        return NULL;
    }
    Root_Distance(root,hash);
    Queue q={NULL,NULL};
    struct TreeNode *temp;
    Enqueue(&q,root);
    while(!IsEmpty(&q)){
        temp=Dequeue(&q);
        if(target->val!=temp->val){
            if(hash[temp->val]-hash[target->val]==k || hash[temp->val]-hash[target->val]==0 || hash[temp->val]-hash[target->val]==-k){
                output[count++]=temp->val;
            }
        }
        if(temp->left)
            Enqueue(&q,temp->left);
        if(temp->right)
            Enqueue(&q,temp->right);
    }
    *returnSize=count;
    return output;
}