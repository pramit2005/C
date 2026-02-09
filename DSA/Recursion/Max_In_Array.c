#include<stdio.h>
#include<limits.h>
int Max_array(int a[],int max,int index){
    if(index==0){
        if(max==INT_MIN || a[0]>max)
            max=a[0];
        return max;
    }
    if(a[index]>max)
        max=a[index];
    return Max_array(a,max,index-1);
}
int main(){
    int arr[5]={101,2,30,4,5};
    printf("\n Max element in the array is: %d",Max_array(arr,INT_MIN,4));
    return 0;
}