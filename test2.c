#include<stdio.h>
#define max 30
void insertion_sort(int *a,int size){
    int key,j;
    for(int i=1;i<size;i++){
        key=a[i];
        for(j=i-1;j>=0 && a[j]>key;j--){
            a[j+1]=a[j];
        }
        a[j+1]=key;
    }
}
void selecton_sort(int *a,int size){
    int key;
    for(int i=0;i<size-1;i++){
        key=i;
        for(int j=i+1;j<size;j++){
            if(a[key]>a[j])
                key=j;
        }
        int temp=a[i];
        a[i]=a[key];
        a[key]=temp;
    }
}
void bubble_sort(int *a,int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1-i;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void merge(int *a,int left,int right,int mid){
    int n1=mid-left+1;
    int n2=right-mid;
    int arr[n1],brr[n2];
    for(int i=0;i<n1;i++)
        arr[i]=a[i+left];
    for(int j=0;j<n2;j++)
        brr[j]=a[j+mid+1];
    int i=0,j=0,k=left;
        while(i<n1 && j<n2){
            if(arr[i]<=brr[j]){
                a[k++]=arr[i++];
            }
            else{
                a[k++]=brr[j++];
            }
        }
        while(i<n1)
            a[k++]=arr[i++];
        while(j<n2)
            a[k++]=brr[j++];
}
void merge_sort(int *a,int left,int right){
    if(left<right){
       int mid=(left+right)/2;
        merge_sort(a,left,mid);
        merge_sort(a,mid+1,right);
        merge(a,left,right,mid);
    }
}
int main(){
    int arr[max],n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,0,n-1);
    printf("The sorted elements of the array: ");
    for(int i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
    return 0;
}