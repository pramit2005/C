#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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
        else if(x>root->data)
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
            temp->left=temp->right=NULL;
            free(temp);
        }
    }
    return root;
}
int max(int a,int b){
    return a>b?a:b;
}
int IsBST(struct node *root){
    if(root==NULL)
        return 1;
    if(root->left && Maximum(root->left)>root->data)
        return 0;
    if(root->right && Minimum(root->right)<root->data)
        return 0;
    if(!IsBST(root->left) && !IsBST(root->right))
        return 0;
    return 1;
}
int IsBST_inorder(struct node *root,int *prev){
    if(!root)
        return 1;
    if(!IsBST_inorder(root->left,prev))
        return 0;
    if(*prev > root->data)
        return 0;
    *prev=root->data;
    return IsBST_inorder(root->right,prev);
}
int Height(struct node *root){
    if(root==NULL)
        return 0;
    else
        return max(Height(root->left),Height(root->right))+1;
}
int main(){
    struct node *root=NULL;
    int n,m,x,a,prev;
    printf("\n Enter the number of nodes to add: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\n Enter the data of the node: ");
        scanf("%d",&m);
        root=Insert(root,m);
    }
    while(1){
    printf("\n 1.Insert\n 2.Delete\n 3.Maximum\n 4.Minimum\n 5.Height\n 6.Inorder display\n 7.IsBST\n 8.Exit");
    printf("\n Enter a option: ");
    scanf("%d",&a);
    switch(a){
        case 1:
            printf("\n Enter the data of the node: ");
            scanf("%d",&m);
            root=Insert(root,m);
            break;
        case 2:
            printf("\n Enter the node to delete: ");
            scanf("%d",&m);
            root=Delete(root,m);
            break;
        case 3:
            printf("\n The maximum element is: %d",Maximum(root));
            break;
        case 4:
            printf("\n The minimum element is: %d",Minimum(root));
            break;
        case 5:
            printf("\n The height of the BST is: %d",Height(root));
            break;
        case 6:
            Inorder(root);
            break;
        case 7:
            prev=INT_MIN;
                if(IsBST_inorder(root,&prev))
                    printf("\n The tree is a BST");
                else
                    printf("\n The tree is not a BST");
                break;
        case 8:
            exit(0);
            break;
        default:
            printf("\n Invalid option");
            break;
        }
    }
    return 0;
}