#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 100
typedef struct heap{
    int *array;
    int count;
    int capacity;
}Heap;
Heap* CreateHeap(int size){
    Heap *h=(Heap*)malloc(sizeof(Heap));
    if(!h){
        printf("\n Memory allocation failed");
        return NULL;
    }
    h->array=(int*)malloc(sizeof(int)*size);
    if(!h->array){
        printf("\n Memory allocation failed");
        return NULL;
    }
    h->count=0;
    h->capacity=size;
    return h;
}
int parent(Heap *h,int i){
    if(i<=0 || i>(h->count))
        return INT_MIN;
    return (i-1)/2;
}
int LeftChild(Heap *h,int i){
    int left=2*i+1;
    if(left>=h->count)
        return INT_MIN;
    return left;
}
int RightChild(Heap *h,int i){
    int right=2*i+2;
    if(right>=h->count)
        return INT_MIN;
    return right;
}
int Getminimum(Heap *h){
    if(h==NULL || h->count==0){
        return INT_MIN;
    }
    return h->array[0];
}
int FindMaxInMinHeap(Heap *h){
    int max=INT_MIN;
    if(h==NULL || h->count==0)
        return INT_MIN;
    for(int i=(h->count+1)/2;i<h->count;i++){
        if(max<h->array[i])
            max=h->array[i];
    }
    return max;
}
void PercolateDown(Heap *h,int i){
    int l,r,temp,min;
    l=LeftChild(h,i);
    r=RightChild(h,i);
    if(l!=INT_MIN && h->array[l]<h->array[i])
        min=l;
    else
        min=i;
    if(r!=INT_MIN && h->array[r]<h->array[min])
        min=r;
    if(min!=i){
        //swapping h->array[i] & h->array[min]
        temp=h->array[i];
        h->array[i]=h->array[min];
        h->array[min]=temp;
        PercolateDown(h,min);
    }
}
int DeleteMin(Heap *h){
    if(h==NULL || h->count==0)
        return INT_MIN;
    int data=h->array[0];
    h->array[0]=h->array[h->count-1];
    h->count--;
    PercolateDown(h,0);
    return data;
}
void ResizeHeap(Heap *h){
    int *old_array=h->array;
    h->array=(int*)malloc(sizeof(int)*(h->capacity)*2);
    if(!h->array){
        printf("\n Memory allocation failed");
        h->array=old_array;
        return;
    }
    h->capacity*=2;
    for(int i=0;i<h->count;i++)
        h->array[i]=old_array[i];
    free(old_array);
}
void Insert(Heap *h,int data){
    if(!h){
        printf("\n Heap does not exists");
        return;
    }
    if(h->count==h->capacity)
        ResizeHeap(h);
    h->count++;
    int i=h->count-1;
    while(i>0 && data<h->array[(i-1)/2]){
        h->array[i]=h->array[(i-1)/2];
        i=(i-1)/2;
    }
    h->array[i]=data;
}
void BuildHeap(Heap *h,int a[],int n){
    if(!h)
        return;
    while(n>h->capacity)
        ResizeHeap(h);
    for(int i=0;i<n;i++){
        h->array[i]=a[i];
    }
    h->count=n;
    for(int j=(n-1)/2;j>=0;j--)
        PercolateDown(h,j);
}
Heap* DestroyHeap(Heap *h){
    if(!h)
        return NULL;
    free(h->array);
    free(h);
    return NULL;
}
void HeapSort(int a[],int n){
    int temp;
    Heap *h=CreateHeap(n);
    BuildHeap(h,a,n);
    for(int i=0;i<n;i++){
        temp=h->array[0];
        h->array[0]=h->array[h->count-1];
        h->array[h->count-1]=temp;
        h->count--;
        PercolateDown(h,0);
    }
    for(int i=0;i<n;i++)
        a[i]=h->array[i];
    h=DestroyHeap(h);
}
void Display_Heap(Heap *h){
    if(!h || !h->count){
        printf("\n Nothing to display");
        return;
    }
    for(int i=0;i<h->count;i++)
        printf(" %d ",h->array[i]);
}
int main(){
    int x,n,a[MAX];
    Heap *h=NULL;
    while(1){
        printf("\n 1.BuildHeap\n 2.Insert\n 3.Delete Min\n 4.Getting Min\n 5.Getting Max\n 6.Destroy Heap\n 7.Display Heap\n 8.Heap Sort\n 9.Exit");
        printf("\nEnter the option: ");
        scanf("%d",&x);
        switch(x){
            case 1:
                printf("\n Enter the number of elements: ");
                scanf("%d",&n);
                printf("\n Enter the elements: ");
                for(int i=0;i<n;i++)
                    scanf("%d",&a[i]);
                if(h==NULL)
                    h=CreateHeap(n);
                BuildHeap(h,a,n);
                break;
            case 2:
                if(h==NULL){
                    printf("\n Enter the capacity of Heap: ");
                    scanf("%d",&x);
                    h=CreateHeap(x);
                }
                printf("\n Enter the data: ");
                scanf("%d",&n);
                Insert(h,n);
                break;
            case 3:
                x=DeleteMin(h);
                if(x==INT_MIN)
                    printf("\n Nothing to delete");
                else
                printf("\n Min deleting element is:%d",x);
                break;
            case 4:
                x=Getminimum(h);
                if(x==INT_MIN)
                    printf("\n Nothing to display");
                else
                printf("\n The min element is:%d",x);
                break;
            case 5:
                x=FindMaxInMinHeap(h);
                if(x==INT_MIN)
                    printf("\n Nothing to display");
                else
                printf("\n The max element is:%d",x);
                break;
            case 6:
                h=DestroyHeap(h);
                break;
            case 7:
                Display_Heap(h);
                break;
            case 8:
                printf("\n Enter the number of elements: ");
                scanf("%d",&n);
                printf("\n Enter the elements: ");
                for(int i=0;i<n;i++)
                    scanf("%d",&a[i]);
                HeapSort(a,n);
                printf("\n Elements after sorting: ");
                for(int i=0;i<n;i++)
                    printf(" %d ",a[i]);
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("\n Invalid option");
                break;
        }
    }
    return 0;
}
