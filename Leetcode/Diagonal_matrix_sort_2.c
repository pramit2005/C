/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void merge(int a[],int left,int mid,int right) {
    int n1=mid-left+1;
    int n2=right-mid;
    int l[n1],r[n2];
    for (int i=0;i<n1;i++)
        l[i]=a[left+i];
    for (int j=0;j<n2;j++)
        r[j]=a[mid+j+1];
    int i=0,j=0,k=left;
    while (i<n1 && j<n2){
        if (l[i]<=r[j]) {
            a[k++]=l[i++];
        }
        else {
            a[k++]=r[j++];
        }
    }
    while (i<n1)
        a[k++]=l[i++];
    while (j<n2)
        a[k++]=r[j++];
}
void merge_sort(int a[],int left,int right) {
    if (left<right) {
        int mid=(right+left)/2;
        merge_sort(a,left,mid);
        merge_sort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}
int** diagonalSort(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
   int i,j,k,l,count;
   int c[100];
   for(i=0,j=0;j<*matColSize;j++){
        count=0;
        for(k=i,l=j;k<matSize && l<*matColSize;k++,l++){
            c[count++]=mat[k][l];
        }
        merge_sort(c,0,count-1);
        count=0;
        for(k=i,l=j;k<matSize && l<*matColSize;k++,l++){
            mat[k][l]=c[count++];
        }
    }

    for(i=0,j=0;i<matSize;i++){
        count=0;
    for(k=i,l=j;k<matSize && l<*matColSize;k++,l++){
            c[count++]=mat[k][l];
        }
        merge_sort(c,0,count-1);
        count=0;
        for(k=i,l=j;k<matSize && l<*matColSize;k++,l++){
            mat[k][l]=c[count++];
        }
    }
    *returnSize=matSize;
    int *a=(int*)malloc(matSize*sizeof(int));
    for(int z=0;z<matSize;z++)
        a[z]=*matColSize;
    *returnColumnSizes=a;
    return mat;
}//still could have done better