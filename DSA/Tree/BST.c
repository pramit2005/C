#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node* Insert(struct node *root,int x){
    if(root==NULL){
        root=(struct node*)malloc(sizeof(struct node));
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
        else 
            root->right=Insert(root->right,x);
    }
    return root;
}
void Inorder(struct node *root){
    if(root==NULL)
        return;
    Inorder(root->left);
    printf(" %d ",root->data);
    Inorder(root->right);
    
}
int Minimum(struct node *root){
    if(root==NULL)
        return -1;
    if(root->left==NULL){
        return root->data;
    }
    Minimum(root->left);
}
int Maximum(struct node *root){
    if(root==NULL){
        return -1;
    }
    if(root->right==NULL){
        return root->data;
    }
    Maximum(root->right);
}
struct node* Delete(struct node *root,int n){
    if(root==NULL){
        printf("\n Element not in the tree");
        return NULL;
    }
    else if(n<root->data)
        root->left=Delete(root->left,n);
    else if(n>root->data)
        root->right=Delete(root->right,n);
    else{
        if(root->left && root->right){
            root->data=Maximum(root->left);
            root->left=Delete(root->left,root->data);
        }
        else{
            struct node *temp=root;
            if(root->left==NULL)
                root=root->right;
            else if(root->right==NULL)
                root=root->left;
            free(temp);
        }
    }
    return root;
}

int main(){
    struct node *root=NULL;
    int n,m;
    printf("\n Enter the number of nodes to add: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\n Enter the data of the node: ");
        scanf("%d",&m);
        root=Insert(root,m);
    }
    printf("\n Inorder representation of the tree: ");
    Inorder(root);
    printf("\n The minimum is: %d",Minimum(root));
    return 0;
}