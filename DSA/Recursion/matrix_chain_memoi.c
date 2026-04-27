#include<stdio.h>
#include<limits.h>
#define max 100
int m[max][max];
int scalar_mat_mul(int p[],int i,int j){
    if(m[i][j]!=INT_MAX)
        return m[i][j];
    else if(i==j)
        return 0;
    else{
        int q;
        for(int k=i;k<j;k++){
            q=scalar_mat_mul(p,i,k)+scalar_mat_mul(p,k+1,j)+(p[i-1]*p[k]*p[j]);
            if(q<m[i][j])
                m[i][j]=q;
        }
        return m[i][j];
    }
}
int main(){
    int n,min;
    printf("\n Enter the number of matrices: ");
    scanf("%d",&n);
    int p[n+1];
    printf("\n Enter the indexes of matrices: ");
    for(int i=0;i<n+1;i++)
        scanf("%d",&p[i]);
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            m[i][j]=INT_MAX;
        }
    }
    min=scalar_mat_mul(p,1,n);
    printf("\n The minimum cost of scalar multiplication is:%d",min);
    return 0;
}
