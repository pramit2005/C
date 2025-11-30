#include<stdio.h>
#include<stdlib.h>
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
void Inorder(Tree *root){
    if(root){
    Inorder(root->left);
    printf(" %d ",root->data);
    Inorder(root->right);
    }
}
void Preorder(Tree *root){
    if(root){
        printf(" %d ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}
int Sum_all_elements(Tree *root){
    int left,right;
    if(root==NULL)
        return 0;
    left=Sum_all_elements(root->left);
    right=Sum_all_elements(root->right);
    return (left+right+root->data);
}
Tree *root=NULL;
int main(){
    int a,b;
    while(1){
        printf("\n 1.Insert\n 2.Display(Level order)\n 3.Preorder\n 4.Inorder\n 5.Sum of elements\n 6.Exit");
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
                Preorder(root);
                break;
            case 4:
                Inorder(root);
                break;
            case 5:
                printf("\n Sum of all elements is: %d",Sum_all_elements(root));
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("\n Invalid opion");
                break;
        }
    }
    return 0;
}