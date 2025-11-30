#include<stdio.h>
void TOH(int n,char src,char aux,char dest){
    TOH(n-1,src,dest,aux);
    printf("\n Moving 1 disc from %c to %c using %c",src,dest,aux);
    TOH(n-1,aux,dest,src)
}