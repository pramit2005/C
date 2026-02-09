#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define max 100
typedef struct tuple{
    int low;
    int high;
    int sum;
}Tuple;
Tuple Find_Max_Crossing_Subarray(int a[],int low,int mid,int high){
    int left_sum=INT_MIN;
    int sum;
    int max_left=mid; 
    sum=0;
    for(int i=mid;i>=low;i--){
        sum=sum+a[i];
        if(sum > left_sum){
            left_sum=sum;
            max_left=i;
        }
    }
    int right_sum=INT_MIN;
    int max_right=mid+1;
    sum=0;
    for(int j=mid+1;j<=high;j++){
        sum=sum+a[j];
        if(sum > right_sum){
            right_sum=sum;
            max_right=j;
        }
    }
    Tuple r={max_left,max_right,left_sum+right_sum};
    return r;
}
Tuple Find_Maximum_Subarray(int a[],int low,int high){
    if(high==low){
        Tuple r={low,high,a[low]};
        return r;
    }
    int mid=(low+high)/2;
    Tuple left=Find_Maximum_Subarray(a,low,mid);
    Tuple right=Find_Maximum_Subarray(a,mid+1,high);
    Tuple cross=Find_Max_Crossing_Subarray(a,low,mid,high);
    if((left.sum > right.sum) && (left.sum > cross.sum))
        return left;
    else if((right.sum > left.sum)&& (right.sum > cross.sum))
        return right;
    else
        return cross;
}
int* Change_in_prices(int* a,int size){
    int *b=(int*)malloc(sizeof(int)*size);
    b[0]=0;
    for(int i=1;i<size;i++){
        b[i]=a[i]-a[i-1];
    }
    return b;
}
int main(){
    int arr[max],n;
    printf("\n Enter the number of days: ");
    scanf("%d",&n);
    printf("\n Enter the prices of each day: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int *b=Change_in_prices(arr,n);
    Tuple Max=Find_Maximum_Subarray(b,0,n-1);
    printf("\n Maximum profit will be if stocks are bought after day %d & sold after day %d & profit will be %d",Max.low,Max.high,Max.sum);
    return 0;
}
//There is Kadane's version of this which is better