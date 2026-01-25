#include<stdio.h>
int main(){
    int a[100],key,n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the numbers : ");
    for(int k=0;k<n;k++){
        scanf("%d",&a[k]);
    }
    for(int j=1;j<n;j++){
        key=a[j];
        for(i=j-1;i>=0 && a[i]>key;i--){
            a[i+1]=a[i];
        }
    a[i+1]=key;
    }
    printf("\n The sorted array is: ");
    for(int k=0;k<n;k++){
        printf(" %d ",a[k]);
    }
    return 0;
}