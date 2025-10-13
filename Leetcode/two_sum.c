
 #include<stdio.h>
 #include<stdlib.h>
 #define max 100
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *a,flag=0;
    *returnSize=2;
    for(int i=0;i<numsSize-1;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                a=(int*)malloc((*returnSize) * sizeof(int));
                a[0]=i;
                a[1]=j;
                flag=1;
                break;
            }
        }
        if (flag==1)
        break;
    }
return a;
}   
int main(){
    int n=2,m,x;
    int c[max];
    printf("\n Enter the number of elements: ");
    scanf("%d",&m);
    printf("\n Enter the elements: ");
    for(int k=0;k<m;k++)
    scanf("%d",&c[k]);
    printf("\n Enter the target: ");
    scanf("%d",&x);
    int *b=twoSum(c,m,x,&n);
    for(int i=0;i<n;i++)
        printf(" %d ",b[i]);
return 0;
}