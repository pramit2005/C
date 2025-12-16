#include<stdio.h>
int main()
{
    int a[]={1,2,3};
    int b[]={10,20,30};
    int c[]={5,6,7};
    int *arr[]={a,b,c};
    int **pp=arr;
    /*pp++;
    printf("%d \n",pp[1][2]);
    printf("%d \n",**(pp++));
    printf("%d \n",(**pp)++);
    printf("%d \n",**pp);*/
    printf("%d",*arr);
    return 0;
}