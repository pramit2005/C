#include<stdio.h>
#include<stdlib.h>
#define N 15
int f=-1,r=-1;
int a[N];
void enqueue(){
    int n;
    if(r==N-1)
    printf("\n The queue is full");

    else{
        printf("\n Enter the number: ");
        scanf("%d",&n);
        if(f==-1 && r==-1)
        f=r=0;
        else
        r++;
        a[r]=n;
    }
}
void dequeue(){
    if(f==-1 || f>r)
    printf("\n The queue is empty");
    else{
        printf("\n The element is: %d",a[f++]);
        if(f>r)
        f=r=-1;

    }
}
void print_queue(){
    if(f==-1 || f>r)
    printf("\n The queue is empty");
    else{
        for(int i=f;i<=r;i++)
        printf(" %d ",a[i]);
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