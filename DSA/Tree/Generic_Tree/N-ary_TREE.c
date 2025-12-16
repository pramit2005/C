#include<stdio.h>
#include<stdlib.h>
#define N 3
typedef struct node{
    int data;
    struct node *first_child;
    struct node *next_sibling;
}GGTree;
typedef struct queue_node{
    struct queue_node*next;
    GTree *ptr;
}QNode;
typedef struct Q{
    QNode *front;
    QNode *rear;
}Queue;
QNode* createNode(GTree *p){
    QNode *Q=(QNode*)malloc(sizeof(QNode));
    if(Q==NULL)
        return NULL;
    Q->ptr=p;
    Q->next=NULL;
    return Q;
}
void Enqueue(Queue *q,GTree *p){
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
GTree* Dequeue(Queue *q){
    if(q->rear==NULL){
        printf("\n Queue is empty");
        return NULL;
    }
    else if(q->front->next==NULL){
        GTree *temp_ptr=q->front->ptr;
        QNode *temp=q->front;
        q->front=NULL;
        q->rear=NULL;
        free(temp);
        return temp_ptr;
    }
    else{
        GTree *temp_ptr=q->front->ptr;
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
int countchildren(GTree *parent){
    int count=0;
    GTree *temp=parent->first_child;
    while(temp){
        count++;
        temp=temp->next_sibling;
    }
    return count;
}
void addchild(GTree *parent,GTree *child){
    if(parent->first_child==NULL)
    parent->first_child=child;
    else{
        GTree *temp=parent->first_child;
        while(temp->next_sibling!=NULL){
            temp=temp->next_sibling;
        }
        temp->next_sibling=child;
    }
}
void Insert(GTree **root_ptr,int x){ //level order traversal
    Queue Q={NULL,NULL};
    GTree *temp;
    GTree *newnode=(GTree*)malloc(sizeof(GTree));
    newnode->data=x;
    newnode->first_child=newnode->next_sibling=NULL;
    GTree *root=*root_ptr;
    if(root==NULL){
    *root_ptr=newnode;
    return;
    }
    Enqueue(&Q,root);
    while(!IsEmpty(&Q)){
        temp=Dequeue(&Q);
        if(temp->left){
            Enqueue(&Q,temp->left);
        }
        else{
            temp->left=newnode;
            Delete_Queue(&Q);
            return;
        }
        if(temp->right){
            Enqueue(&Q,temp->right);
        }
        else{
            temp->right=newnode;
            Delete_Queue(&Q);
            return;
        }
    }
    Delete_Queue(&Q);
}//Not completed,Have to set a maximum number of children before going to the next node