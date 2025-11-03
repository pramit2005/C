#include<stdio.h>
int main()
{
    int a;
    int flag=1;
    int b;
    printf("enter a num:");
    scanf("%d\n",&b);
    for(a=2;a<(b-1)/2;a++)
    {
        if(b%a==0)
        {
            flag=0;
        }
    }
        if(flag==0)
        {
            printf("The num is not prime num:%d\n",a);
        }
        else if(flag==1)
        {
            printf("The num is prime num:%d\n",a);
        }
        return 0;
}