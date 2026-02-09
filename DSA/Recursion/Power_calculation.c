#include<stdio.h>
int Power(int x,int n){
    if(n==0)
        return 1;
    else if(n==1)
        return x;
    return x*Power(x,n-1);
}
int main(){
    int a,b;
    printf("\n Enter the base: ");
    scanf("%d",&a);
    printf("\n Enter the exponent: ");
    scanf("%d",&b);
    printf("%d^%d is:%d",a,b,Power(a,b));
    return 0;
}