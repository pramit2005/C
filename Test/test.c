#include<stdio.h>
#define max 100
void Merge(int *a,int low,int mid,int high){
    int n1=mid-low+1;
    int n2=high-mid;
    int l[n1],r[n2];
    for(int i=0;i<n1;i++){
        l[i]=a[i+low];
    }
    for(int j=0;j<n2;j++){
        r[j]=a[j+mid+1];
    }
    int i=0,j=0,k=low;
    while(i<n1 && j<n2){
        if(l[i]<=r[j]){
            a[k++]=l[i++];
        }
        else
            a[k++]=r[j++];
    }
    while(i<n1)
        a[k++]=l[i++];
    while(j<n2)
        a[k++]=r[j++];
}
void Merge_Sort(int *a,int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        Merge_Sort(a,0,mid);
        Merge_Sort(a,mid+1,high);
        Merge(a,0,mid,high);
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
    Merge_Sort(a,0,n-1);
    printf("\n The array after sorting: ");
    for(int j=0;j<n;j++)
    printf(" %d ",a[j]);
    return 0;
}