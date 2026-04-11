#include<stdio.h>
int Climbing_staircases(int n){
    if(n<0)
        return 0;
    else if(n==1 || n==0)
        return 1;
    else{
        return Climbing_staircases(n-1)+Climbing_staircases(n-2);
    }
}
int main(){
    int n;
    printf("\n Enter the number of steps: ");
    scanf("%d",&n);
    printf("\n Number of possible steps taking either 1 or 2 steps: %d",Climbing_staircases(n));
    return 0;
}