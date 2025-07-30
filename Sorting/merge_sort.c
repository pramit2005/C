#include<stdio.h>
#define MAX 100
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
   void printarr(int a[],int size) {
       for (int i=0;i< size ;i++) {
           printf("%d ",a[i]);
       }
    printf("\n");
   }
int main(){
    int arr[MAX],n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for (int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    printf("Original array:\n");
    printarr(arr,n);
    merge_sort(arr,0,n-1);
    printarr(arr,n);
    return 0;
}

