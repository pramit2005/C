#include<stdio.h>
#define max 100
int Binary_search(int* a,int low,int high,int x){
    if(low>high)
        return -1;
    else{
       int mid=low+(high-low)/2;
    if(x==a[mid])
        return mid;
    else if(x>a[mid])
        return Binary_search(a,mid+1,high,x);
    else if(x<a[mid])
        return Binary_search(a,low,mid-1,x);
    }
}
int main(){
    int arr[max],n,x,k;
    printf("\n Enter the number of elements: ");
    scanf("%d",&n);
    printf("\n Enter the elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\n Enter an element to search: ");
    scanf("%d",&x);
    k=Binary_search(arr,0,n-1,x);
    k==-1?printf("\n Element not found"):printf("\n Element found at position:%d",k+1);
    return 0;
}