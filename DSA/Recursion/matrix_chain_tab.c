#include<stdio.h>
#include<limits.h>
#define max 100
int m[max][max];
void matrix_chain_mul(int p[],int n){
    int q;
    for(int z=0;z<n;z++)
        m[z][z]=0;
    for(int l=2;l<=n-1;l++){
        for(int i=1;i<=n-1;i++){
            int j=i+l-1;
            m[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(q<m[i][j])
                    m[i][j]=q;
            }
        }
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
    matrix_chain_mul(p,n+1);
    printf("\n The minimum cost of scalar multiplication is:%d",m[1][n]);
    return 0;
} 