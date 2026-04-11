#include<stdio.h>
#include<math.h>
typedef struct pts{
    int x;
    int y;
}point;
typedef struct node{
    point p1;
    point p2;
    double dist;
}Pair;
double distance(point p1,point p2){
    double d;
    int d1,d2;
    d1=p1.x-p2.x;
    d2=p2.y-p2.y;
    d=sqrt(d1*d1+d2*d2);
    return d;
}
//Thinking of solving this problem in similar way as Maximum subarray problem,as the pair of points could be in left side,right side or in a crossing manner
/*void Closest_Pairs(point p[],int low,int high,int mid,int *min1,int *min2,int min){  //This problem is solved using Divide & Conquer
    int n1=mid-low+1;
    int n2=high-mid;
    int l[n1][2],r[n2][2];
    for(int i=0;i<n1;i++){
        l[i][0]=points[low+i][0];
        l[i][1]=points[low+i][1];
    }
    for(int j=0;j<n2;j++){
        r[j][0]=points[mid+j+1][0];
        r[j][1]=points[mid+j+1][1];
    }
    int i=0,j=0,k=low;
    while(i<n1 && j<n2){
        if(l[i][0]<=r[j][0]){
            points[k][0]=l[i][0];
            points[k][1]=l[i][1];
            if()
            
        }
    }
}
*/
Pair Find_Pair_Crossing_Mid(point p[],int low,int mid,int high){
    

}