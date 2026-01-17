#include<stdio.h>
#include<stdlib.h>
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
void Inorder(struct TreeNode *root){
    if(root==NULL)
        return;
    Inorder(root->left);
    printf(" %d ",root->data);
    Inorder(root->right);
    
}
int Minimum(struct TreeNode *root){
    if(root==NULL)
        return -1;
    if(root->left==NULL){
        return root->data;
    }
    Minimum(root->left);
}
int Maximum(struct TreeNode *root){
    if(root==NULL){
        return -1;
    }
    if(root->right==NULL){
        return root->data;
    }
    Maximum(root->right);
}
struct TreeNode* Delete(struct TreeNode *root,int n){
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
            struct TreeNode *temp=root;
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
int Height(struct TreeNode *root){
    if(root==NULL)
        return 0;
    else
        return max(Height(root->left),Height(root->right))+1;
}
struct TreeNode* BST2DLL(struct TreeNode *root,struct TreeNode **tail){
    struct TreeNode *left,*right,*ltail,*rtail;//ltail & rtail is the tail of left & right subtree
    if(!root){
        *tail=NULL;
        return NULL;
    }
    left=BST2DLL(root->left,&ltail); //left is the head of left subtree
    right=BST2DLL(root->right,&rtail);//right is the head of right subtree
    if(left){           //linking left subtree with root 
    ltail->right=root;
    root->left=ltail;
    }
    if(right){          //linking root with right subtree
        root->right=right;
        right->left=root;
    }
    if(right)
        *tail=rtail;    //this is how the rtail & ltail is getting initiazed without explicitly doing so
    else
        *tail=root;
    if(left)            //returning the head
        return left;
    else
        return root;
}
void CDLL_display(struct TreeNode *head,struct TreeNode *tail){
    struct TreeNode *temp=head;
    if(temp==NULL)
        printf("\n Nothing to display");
    else{
        do{
            printf("->%d-",temp->data);
            temp=temp->right;
        }while(temp!=tail->right);
    }
}
int main(){
    struct TreeNode *root=NULL,*head=NULL,*tail=NULL;
    int n,m,x,a;
    printf("\n Enter the number of TreeNodes to add: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\n Enter the data of the TreeNode: ");
        scanf("%d",&m);
        root=Insert(root,m);
    }
    while(1){
    printf("\n 1.Insert\n 2.Delete\n 3.Maximum\n 4.Minimum\n 5.Height\n 6.Inorder display\n 7.BST to CDLL\n 8.CDLL display\n 9.Exit");
    printf("\n Enter a option: ");
    scanf("%d",&a);
    switch(a){
        case 1:
            printf("\n Enter the data of the TreeNode: ");
            scanf("%d",&m);
            root=Insert(root,m);
            break;
        case 2:
            printf("\n Enter the TreeNode to delete: ");
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
            head=BST2DLL(root,&tail);
            if(head && tail){
                head->left=tail;
                tail->right=head;
            }
            break;
        case 8:
            CDLL_display(head,tail);
            break;

        case 9:
            exit(0);
            break;
        default:
            printf("\n Invalid option");
            break;
        }
    }
    return 0;
}