#include<stdio.h>
int main()
{
    int a[5];
    printf("\n Enter the elements: "); 
    for(int i=0;i<5;i++)
        scanf("%d",&a[i]);
    for(int j=0;j<5;j++)
        printf(" %d ",a[j]);
        return 0;
}