#include<stdio.h>
int f[20];
int fib(int n){
    if (n==0  || n==1)
        return n;
    else{
        if(f[n-1]==-1)
            f[n-1]=fib(n-1);
        if(f[n-2]==-1)
            f[n-2]=fib(n-2);
        return f[n-2]+f[n-1];
    }
}
int main(){
    int x;
    for(int i=0;i<20;i++)
        f[i]=-1;
    printf("\n Enter the number of terms: ");
    scanf("%d",&x);
    for(int i=0;i<x;i++)
        printf(" %d ",fib(i));
    return 0;
}