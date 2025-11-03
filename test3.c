#include<stdio.h>
float area()
{
    int r;
    float pie=3.14;
    printf("enter the radius:");
    scanf("%d",&r);
    float a=pie*(r*r);
    return a;
}
int main()
{
    float b=0;
    b=area();
    printf("%d",b);
    return 0;
}