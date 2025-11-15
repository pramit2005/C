#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node{
    struct node *left;
    struct node *right;
    int data;
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
void Insert(Tree **root_ptr,int x){ //level order traversal
    Queue Q={NULL,NULL};
    Tree *temp;
    Tree *newnode=(Tree*)malloc(sizeof(Tree));
    newnode->data=x;
    newnode->left=newnode->right=NULL;
    Tree *root=*root_ptr;
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
}
void display(Tree *root){ //level order traversal
    Tree *temp;
    if(root==NULL){
        printf("\n The tree is empty");
        return;
    }
    Queue q={NULL,NULL};
    Enqueue(&q,root);
    while(!IsEmpty(&q)){
        temp=Dequeue(&q);
        printf(" %d ",temp->data);
        if(temp->left)
            Enqueue(&q,temp->left);
        if(temp->right)
            Enqueue(&q,temp->right);
    }
    Delete_Queue(&q);
}
int Max(Tree *root){ 
    Queue Q={NULL,NULL};
    int max=INT_MIN;
    Tree *temp;
    Enqueue(&Q,root);
    while(!IsEmpty(&Q)){
        temp=Dequeue(&Q);
        if(temp->data>max)
            max=temp->data;
        if(temp->left)
            Enqueue(&Q,temp->left);
        if(temp->right)
            Enqueue(&Q,temp->right);
    }
    Delete_Queue(&Q);
    return max;
}
Tree *root=NULL;
int main(){
    int a,b;
    while(1){
        printf("\n 1.Insert\n 2.Display(Level order)\n 3.Find Maximum\n 5.Exit");
        printf("\n Enter a option: ");
        scanf("%d",&a);
        switch(a){
            case 1:
                printf("\n Enter the data: ");
                scanf("%d",&b);
                Insert(&root,b);
                break;
            case 2:
                display(root);
                break;
            case 3:
                printf("\n The max is : %d",Max(root));
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\n Invalid opion");
                break;
        }
    }
    return 0;
}