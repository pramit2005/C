#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node *left;
    struct node *right;
    int data;
    int height;
}AVLTreeNode;
int Height(AVLTreeNode *root){
    if(!root)
        return -1;
    else
        return root->height; 
}
int max(int a,int b){
    return a>b?a:b;
}
AVLTreeNode* SingleRightRotation(AVLTreeNode *X){
    AVLTreeNode *W=X->left;
    X->left=W->right;
    W->right=X;
    X->height=max(Height(X->left),Height(X->right))+1;
    W->height=max(Height(W->left),Height(W->right))+1;
    return W;
}
AVLTreeNode* SingleLeftRotation(AVLTreeNode *W){
    AVLTreeNode *X=W->right;
    W->right=X->left;
    X->left=W;
    W->height=max(Height(W->left),Height(W->right))+1;
    X->height=max(Height(X->left),Height(X->right))+1;
    return X;
}
AVLTreeNode* DoubleLR(AVLTreeNode *Z){
    Z->left=SingleLeftRotation(Z->left);
    return SingleRightRotation(Z);
}
AVLTreeNode* DoubleRL(AVLTreeNode *Z){
    Z->right=SingleRightRotation(Z->right);
    return SingleLeftRotation(Z);
}
AVLTreeNode* Insert(AVLTreeNode* root,int x){
    if(!root){
        root=(AVLTreeNode*)malloc(sizeof(AVLTreeNode));
        if(!root)
            return NULL;
        else{
            root->data=x;
            root->left=root->right=NULL;
            root->height=0;
        }
    }
    else if(x<root->data){  
        root->left=Insert(root->left,x);
        if(Height(root->left)-Height(root->right)==2){
            if(x<root->left->data)
                root=SingleRightRotation(root);
            else
                root=DoubleLR(root);
        }
    }
    else if(x>root->data){
        root->right=Insert(root->right,x);
        if(Height(root->right)-Height(root->left)==2){
            if(x>root->right->data)
                root=SingleLeftRotation(root);
            else
                root=DoubleRL(root);
        }
    }
    root->height=max(Height(root->left),Height(root->right))+1;
    return root;
}
