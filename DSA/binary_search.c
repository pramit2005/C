#include<stdio.h>
#define max 30
int binary_search(int a[],int n,int x){
    int left=0,right=n-1,mid;
    mid=(left+right)/2;
    while(left<right){
        if(a[mid]==x)
        return mid;
        else if(a[mid]<x)
        left=mid+1;
        else
        right=mid-1;
    }
    return -1;
}
int main(){
    int a[max],m,y,index;
    printf("\n Enter the number of elements of the array: ");
    scanf("%d",&m);
    printf("\n Enter the elements of the array: ");
    for(int i=0;i<m;i++)
    scanf("%d",&a[i]);
    printf("\n Enter the element to search: ");
    scanf("%d",&y);
    index=binary_search(a,m,y);
    if(index==-1)
    printf("\n Element not found ");
    else
    printf("\n The element found at position: %d",index+1);
    return 0;
}