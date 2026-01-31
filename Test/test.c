#include<stdio.h>
int main(){
    int a[][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {10}
    };
    int rows=sizeof(a)/sizeof(a[0]);
    int col=sizeof(a[0])/sizeof(a[0][0]); //no of elements in a row=number of colomns
    printf("\nThe  elements of the array: ");
    for(int i=0;i<rows;i++)
        for(int j=0;j<col;j++)
            printf(" %d ",a[i][j]);
    return 0;
}