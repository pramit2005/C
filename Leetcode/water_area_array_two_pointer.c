#include<stdio.h>
#define size 30
int maxArea( int* height,int heightSize){
    int left=0;
    int right=heightSize-1;
    int max=0;
    while(left<right){
    int h=height[left]<height[right]?height[left]:height[right];
    int area=h*(right-left);
    if(area>max)
    max=area;
        if(height[left]<height[right])
        left++;
        else 
        right--;
    }
    return max;
}
int main(){
     int a[size],m,p;
    printf("\n Enter the size of the array: ");
    scanf("%d",&m);
    printf("\n Enter the elements of the array: ");
    for(int x=0;x<m;x++)
    scanf("%d",&a[x]);
    printf("\n The maximum water area is: %d",maxArea(a,m));
    return 0;
}
