#include<stdio.h>
#define max 30
int binary_search_recursive(int a[],int left,int right,int x){
    int mid=(left+right)/2;
    if(left>right)
    return -1;
    else{
        if(a[mid]==x)
        return mid;
        else if(a[mid]<x)
        return binary_search_recursive(a,mid+1,right,x);
        else
        return binary_search_recursive(a,left,mid-1,x);
    }
}
int main(){
    int a[max],m,y,index,l,r;
    printf("\n Enter the number of elements of the array: ");
    scanf("%d",&m);
    printf("\n Enter the elements of the array: ");
    for(int i=0;i<m;i++)
    scanf("%d",&a[i]);
    printf("\n Enter the element to search: ");
    scanf("%d",&y);
    l=0;
    r=m-1;
    index=binary_search_recursive(a,l,r,y);
    if(index==-1)
    printf("\n Element not found ");
    else
    printf("\n The element found at position: %d",index+1);
    return 0;
}