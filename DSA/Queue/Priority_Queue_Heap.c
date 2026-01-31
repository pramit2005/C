#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct heap{
    int* array;
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
int PQ_peek(Heap *h){
    if(h==NULL || h->count==0){
        return INT_MIN;
    }
    return h->array[0];
}
Heap* DestroyHeap(Heap *h){
    if(!h)
        return NULL;
    free(h->array);
    free(h);
    return NULL;
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
int PQ_Dequeue(Heap *h){
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
void PQ_Enqueue(Heap *h,int data){
    if(!h){
        printf("\n Queue does not exists");
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
int PQ_IsEmpty(Heap *h){
    if(!h || !h->count)
        return 1;
    return 0;
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
    int x,n,a;
    Heap *h=NULL;
    while(1){
        printf("\n 1.Enqueue\n 2.Dequeue\n 3.Peek\n 4.IsEmpty\n 5.Display\n 6.Exit");
        printf("\n Enter a option: ");
        scanf("%d",&a);
        switch(a){
            case 1:
                if(!h){
                    printf("\n Enter the queue capacity: ");
                    scanf("%d",&n);
                    h=CreateHeap(n);
                }
                printf("\n Enter the data: ");
                scanf("%d",&x);
                PQ_Enqueue(h,x);
                break;
            case 2:
                x=PQ_Dequeue(h);
                if(x==INT_MIN)
                    printf("\n Queue is empty");
                else
                    printf("\n Dequeued element is:%d",x);
                break;
            case 3:
                x=PQ_peek(h);
                if(x==INT_MIN)
                    printf("\n Queue is empty");
                else
                    printf("Peeked element is:%d",x);
                break;
            case 4:
                PQ_IsEmpty(h)?printf("\n Queue is empty"):printf("\n Queue is not empty");
                break;
            case 5:
                Display_Heap(h);
                break;
            case 6:
                h=DestroyHeap(h);
                exit(0);
                break;
            default:
                printf("\n Invalid option");
                break;
        }
    }
    return 0;
}
