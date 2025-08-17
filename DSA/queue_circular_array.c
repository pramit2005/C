#include<stdio.h>
#include<stdlib.h>
#define N 7
int f=-1,r=-1;
int a[N];
void enqueue(){
    int n;
    if((r+1)%N==f)
    printf("\n The queue is full");

    else{
        printf("\n Enter the number: ");
        scanf("%d",&n);
        if(f==-1 && r==-1)
        f=r=0;
        else
        r=(r+1)%N;
        a[r]=n;
    }
}
void dequeue(){
    if(f==-1 || r==-1)
    printf("\n The queue is empty");
    else{
        printf("\n The element is: %d",a[f]);
        if(f==r && f!=-1)
        f=r=-1;
        else
        f=(f+1)%N;
    }
}
void print_queue(){
    if(f==-1 || r==-1)
    printf("\n The queue is empty");
    else{
       int i=f;
       while(1){
       printf(" %d ",a[i]);
       if(i==r)
       break;
       i=(i+1)%N;
       }
    }
}
int main(){
    int a;
    while(1){
    printf("\n 1.Enqueue \n 2. Dequeue \n 3.Print \n 4.Exit");
    printf("\n Enter a option: ");
    scanf("%d",&a);
        switch(a){
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            print_queue();
            break;
            case 4:
            exit(0);
            default:
            printf("\n Invalid option");
        }

    }
return 0;
}