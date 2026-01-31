#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* Insert(struct TreeNode *root,int x){
    if(root==NULL){
        root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        if(root==NULL){
            printf("\n Memory error");
            return NULL; 
        }
        root->data=x;
        root->left=root->right=NULL;
    }
    else{
        if(x<root->data)
            root->left=Insert(root->left,x);
        else if(x>root->data)
            root->right=Insert(root->right,x);
    }
    return root;
}
int max(int a,int b){
    return a>b?a:b;
}
int Floor_In_BST(struct TreeNode *root,int key){    //Floor is the largest key in BST smaller or equal than key
    int root_key;
    if(root->data > key){

        return Floor_In_BST(root->left,key);
    }
    
}