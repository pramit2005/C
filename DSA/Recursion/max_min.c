#include<stdio.h>
#define max 100
void find_max_min(int arr[],int low,int high,int maxmin[]){
    if(low==high)
        maxmin[0]=maxmin[1]=arr[low];
    else if (high==low+1){
        if(arr[low]<arr[high]){
            maxmin[0]=arr[low];
            maxmin[1]=arr[high];
        }
        else{
            maxmin[0]=arr[high];
            maxmin[1]=arr[low];
        }
    }
    else{
        if(low<high){
        int Leftmaxmin[2],Rightmaxmin[2];
        int mid=(low+high)/2;
        find_max_min(arr,low,mid,Leftmaxmin);
        find_max_min(arr,mid+1,high,Rightmaxmin);
        maxmin[0]=(Leftmaxmin[0]<Rightmaxmin[0])?Leftmaxmin[0]:Rightmaxmin[0];
        maxmin[1]=(Leftmaxmin[1]>Rightmaxmin[1])?Leftmaxmin[1]:Rightmaxmin[1];
        }
    }
}
int main(){
    int a[max],n,maxmin[2];
    printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("\n Enter the elements:");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    find_max_min(a,0,n-1,maxmin);
    printf("\n The max element is:%d & The minimum element is:%d",maxmin[1],maxmin[0]);
    return 0;
}