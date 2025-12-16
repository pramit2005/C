#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Tree;
typedef struct node{
    struct node *next;
    Tree *ptr;
}SNode;
typedef struct s{
    SNode *top;
}Stack;
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
void push(Stack *S,Tree *data){
    SNode *newnode=(SNode*)malloc(sizeof(SNode));
    newnode->ptr=data;
    if(S->top==NULL){
        newnode->next=NULL;
        S->top=newnode;
    }
    else{
        newnode->next=S->top;
        S->top=newnode;
    }
}
Tree* pop(Stack *S){
    Tree* p;
    if(S->top==NULL){
        printf("\n Stack is empty");
        return NULL;
    }
    SNode *temp=S->top;
    p=S->top->ptr;
    S->top=S->top->next;
    temp->next=NULL;
    free(temp);
    return p;
}
int IsEmptyS(Stack *s){
    return (s->top==NULL);
}
void Delete_Stack(Stack *s){
    SNode *temp;
    if(s->top==NULL){
        return;
    }
    while(s->top){
    temp=s->top;
    s->top=s->top->next;
    temp->next=NULL;
    free(temp);
    }
}
void Non_recursive_Preorder(Tree *root){
    Stack S={NULL};
    if(root==NULL){
        printf("\n The tree is empty");
        return;
    }
    while(1){
        while(root){
            printf(" %d ",root->data);
            push(&S,root);
            root=root->left;
        }
        if(IsEmptyS(&S)){
            break;
        }
        root=pop(&S);
        
        root=root->right;
    }
    Delete_Stack(&S);
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
Tree *root=NULL;
int main(){
     int a,b;
    while(1){
        printf("\n 1.Insert\n 2.Display(Level order)\n 3.Non Recursive Preorder\n 4.Exit");
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
                Non_recursive_Preorder(root);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\n Invalid opion");
                break;
        }
    }
return 0;
}