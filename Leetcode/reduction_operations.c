#include<stdio.h>
#include<stdlib.h>
int IsEqual(int *nums,int numsSize){
    int x=nums[0],flag=1;
    for(int i=0;i<numsSize;i++){
        if(x!=nums[i])
            flag=0;
    }
    return flag;
}
int last_lowest(int *nums,int numsSize){
    int x=nums[0],ind=0;
    for(int i=0;i<numsSize;i++){
        if(x==nums[i])
            ind=i;
    }
    return ind;
}
void merge(int a[],int left,int mid,int right) {
    int n1=mid-left+1;
    int n2=right-mid;
    int l[n1],r[n2];
    for (int i=0;i<n1;i++)
        l[i]=a[left+i];
    for (int j=0;j<n2;j++)
        r[j]=a[mid+j+1];
    int i=0,j=0,k=left;
    while (i<n1 && j<n2){
        if (l[i]<=r[j]) {
            a[k++]=l[i++];
        }
        else {
            a[k++]=r[j++];
        }
    }
    while (i<n1)
        a[k++]=l[i++];
    while (j<n2)
        a[k++]=r[j++];
}
void merge_sort(int a[],int left,int right) {
    if (left<right) {
        int mid=(right+left)/2;
        merge_sort(a,left,mid);
        merge_sort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}
int reductionOperations(int* nums, int numsSize) {
    int steps=0,grps=0,a;
    merge_sort(nums,0,numsSize-1);
    for(int i=1;i<numsSize;i++){
            if(nums[i]!=nums[i-1]){
                grps++;
            }
            steps+=grps;
    }
    return steps;
}
    int main(){
        int a[]={7,9,10,8,6,4,1,5,2,3};
        printf(" Number of steps: %d",reductionOperations(a,10));
        return 0;
    }