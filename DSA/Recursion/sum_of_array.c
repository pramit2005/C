#include<stdio.h>
int Sum_of_array(int* a,int index){
    if(index==0)
        return a[0];
    else
    return a[index]+Sum_of_array(a,index-1);
}
int main(){
    int arr[5]={1,2,3,4,5};
    printf("sum of the array is: %d",Sum_of_array(arr,4));
    return 0;
}