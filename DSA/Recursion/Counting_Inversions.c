#include<stdio.h>
#include<stdio.h>
#define max 100
void combine(int *arr,int low,int mid,int high,int *count){
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
        else{
            arr[k++]=r[j++];
            (*count)+=(n1-i);
        }
    }
    while(i<n1)
        arr[k++]=l[i++];
    while(j<n2)
        arr[k++]=r[j++];
}
void Count_Inversions(int *arr,int low,int high,int *count){
    if(low<high){
        int mid=(low+high)/2;
        Count_Inversions(arr,low,mid,count);
        Count_Inversions(arr,mid+1,high,count);
        combine(arr,low,mid,high,count);
    }
}
int main(){
    int arr[max],n;
    int count=0;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for (int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    Count_Inversions(arr,0,n-1,&count);
    printf("\n Number of inversions:%d",count);
    return 0;
}