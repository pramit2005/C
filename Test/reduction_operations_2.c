#include<stdio.h>
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
        if (l[i]>=r[j]) {
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
    int steps=0;
    merge_sort(nums,0,numsSize-1);
    for(int i=0;i<numsSize-1;i++){
        if(nums[i]!=nums[i+1]){
            steps=steps+i+1;
        }
    }
    return steps;
}
int main(){
        int a[]={1,1,2,2,3};
        printf(" Number of steps: %d",reductionOperations(a,5));
        return 0;
}