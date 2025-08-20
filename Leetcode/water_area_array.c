#include<stdio.h>
#define size 30
int  water_area(int a[],int n){
    int max=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]>=a[i]){
                if((a[i]*(j-i))>max)
                max=a[i]*(j-i);
            }
        }
    }
    for(int k=n-1;k>0;k--){
        for(int l=k-1;l>=0;l--){
            if(a[l]>=a[k]){
                if((a[k]*(k-l))>max)
                max=a[k]*(k-l);
            }
        }
    }
    return max;
    
}
int main(){
    int a[size],m,p;
    printf("\n Enter the size of the array: ");
    scanf("%d",&m);
    printf("\n Enter the elements of the array: ");
    for(int x=0;x<m;x++)
    scanf("%d",&a[x]);
    printf("\n The maximum water area is: %d",water_area(a,m));
    return 0;
}