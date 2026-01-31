#include<stdio.h>
int main(){
    int i,j;
    int mat[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    printf("\n Diagonal of this matrix is: ");
    for(i=0,j=0;i<3 && j<3;i++,j++)
        printf(" %d",mat[i][j]);
    return 0;
}