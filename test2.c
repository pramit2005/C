#include<stdio.h>
int main()
{
    int a=0;
    for(int i=0;i<=11;i++)
        a=a+(i%3);
    printf("\n a= %d",a);
        return 0;
}