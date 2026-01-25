#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct heap{
    int *array;
    int count;      //Number of elements in the heap
    int capacity;   //Size of the heap
    int heap_type;  //Min Heap or Max Heap
}Heap;
Heap* CreateHeap(int capacity){
    Heap *h=(Heap*)malloc(sizeof(Heap));
    if(h==NULL){
        printf("Memory allocation failed");
        return NULL;
    }
    h->capacity=capacity;
    h->count=0;
    h->array=(int*)malloc(sizeof(int)*capacity);
    if(h->array==NULL){
        printf("\n Memory allocation failed");
        return NULL;
    }
    return h;
}
int parent(Heap *h,int i){
    if(i<=0 || i>=h->count)
        return -1;
    return (i-1)/2;
}
int LeftChild(Heap *h,int i){
    int left=2*i+1;
    if(left>=h->count)
        return -1;
    return left;
}
int RightChild(Heap *h,int i){
    int right=2*i+2;
    if(right>=h->count)
        return -1;
    return right;
}
int GetMaximum(Heap *h){    //This code is done considering this as Max Heap
    if(h==NULL || h->count==0)
        return -1;
    return h->array[0];
}
void PercolateDown(Heap *h,int i){  //'i' is index where heap property is violated at first
    int l,r,max,temp;
    l=LeftChild(h,i);
    r=RightChild(h,i);
    if(l!=-1 && h->array[l]>h->array[i])
        max=l;
    else
        max=i;
    if(r!=-1 && h->array[r]>h->array[max])
        max=r;
    if(max!=i){
        //swap h->array[i] & h->array[max]
        temp=h->array[i];
        h->array[i]=h->array[max];
        h->array[max]=temp;
        PercolateDown(h,max);
    }
}
int DeleteMax(Heap *h){
    int data;
    if(h->count==0)
        return -1;
    data=h->array[0];
    h->array[0]=h->array[h->count-1];   //Putting the rightmost(last) element in root
    h->count--;
    PercolateDown(h,0);
    return data;
}
void ResizeHeap(Heap *h){
    int *array_old=h->array;
    h->array=(int*)malloc(sizeof(int)*(h->capacity)*2);
    if(h->array==NULL){
        printf("\n Memory allocation failed");
        h->array=array_old;
        return;
    }
    for(int i=0;i<h->capacity;i++)
        h->array[i]=array_old[i];
    h->capacity*=2;
    free(array_old);
}
void Insert(Heap *h,int data){   //Inserting at the last(rightmost) element,then using Percolate Up
    int i;
    if(h->count==h->capacity)
        ResizeHeap(h);
    h->count++;                 //Increasing the heapsize to insert at last position
    i=h->count-1;
    while(i>0 && data>h->array[(i-1)/2]){
        h->array[i]=h->array[(i-1)/2];
        i=(i-1)/2;
    }
    h->array[i]=data; 
}
Heap* DestroyHeap(Heap *h){
    if(h==NULL)
        return NULL;
    free(h->array);
    free(h);
    h=NULL;
    return h;
}
void BuildHeap(Heap *h,int a[],int n){
    if(h==NULL)
        return;
    while(n>h->capacity)
        ResizeHeap(h);

    for(int i=0;i<n;i++)
        h->array[i]=a[i];
    h->count=n;
    for(int j=(n-1)/2;j>=0;j--) //Finding the last parent node
        PercolateDown(h,j);
}
void HeapSort(int a[],int n){
    int old_size,i,temp;
    Heap *h=CreateHeap(n);
    BuildHeap(h,a,n);
    old_size=h->count;
    for(i=n-1;i>0;i--){
        temp=h->array[0];
        h->array[0]=h->array[h->count-1];
        h->array[h->count-1]=temp;
        h->count--;
        PercolateDown(h,0);
    }
    h->count=old_size;
    for(int j=0;j<n;j++)
        a[j]=h->array[j];    
}
void Display_Heap(Heap *h){
    if(h==NULL || h->count==0){
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
        printf("\n 1.BuildHeap\n 2.Insert\n 3.Delete Max\n 4.Getting Max\n 5.Destroy Heap\n 6.Display Heap\n 7.Heap Sort\n 8.Exit");
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
                x=DeleteMax(h);
                if(x==-1)
                    printf("\n Nothing to delete");
                else
                printf("\n Max deleting element is:%d",x);
                break;
            case 4:
                printf("\n The max element is:%d",GetMaximum(h));
                break;
            case 5:
                h=DestroyHeap(h);
                break;
            case 6:
                Display_Heap(h);
                break;
            case 7:
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
            case 8:
                exit(0);
                break;
            default:
                printf("\n Invalid option");
                break;
        }
    }
    return 0;
}
