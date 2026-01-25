/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** diagonalSort(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
   int i,j,k,l,r,c,x;
   for(i=0,j=0;j<*matColSize;j++){
    for(k=i,l=j;k<matSize && l<*matColSize;k++,l++){
        for(r=k,c=l;r<matSize && c<*matColSize;r++,c++){
            if(mat[k][l]>mat[r][c]){
                x=mat[k][l];
                mat[k][l]=mat[r][c];
                mat[r][c]=x;
                }
            }
        }
    }
    for(i=0,j=0;i<matSize;i++){
    for(k=i,l=j;k<matSize && l<*matColSize;k++,l++){
        for(r=k,c=l;r<matSize && c<*matColSize;r++,c++){
            if(mat[k][l]>mat[r][c]){
                x=mat[k][l];
                mat[k][l]=mat[r][c];
                mat[r][c]=x;
                }
            }
        }
    }
    *returnSize=matSize;
    int *a=(int*)malloc(matSize*sizeof(int));
    for(int z=0;z<matSize;z++)
        a[z]=*matColSize;
    *returnColumnSizes=a;
    return mat;
}
//Less optimized with T.C=O(n^3) 