#include<stdio.h>
#define max 100
void merge(int *arr,int low,int mid,int high){
    int n1=mid-low+1;
    int n2=high-mid;
    int l[n1],r[n2];
    for(int i=0;i<n1;i++)
        l[i]=arr[low+i];
    for(int j=0;j<n2;j++)
        r[j]=arr[mid+j+1];
    int i=0,j=0,k=low;
    while(i<n1 && j<n2){
        if(l[i]<=r[j]){
            arr[k++]=l[i++];
        }
        else
            arr[k++]=r[j++];
    }
    while(i<n1)
        arr[k++]=l[i++];
    while(j<n2)
        arr[k++]=r[j++];
}
void merge_sort(int *arr,int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main(){
    int a[max];
    int n;
    printf("\n Enter the number of elements: ");
    scanf("%d",&n);
    printf("\n Enter the elements: ");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    merge_sort(a,0,n-1);
    printf("\n The array after sorting: ");
    for(int j=0;j<n;j++)
    printf(" %d ",a[j]);
    return 0;
}