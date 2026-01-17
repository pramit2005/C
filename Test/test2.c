#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*tail=NULL;
void creat_csll(int h)
{
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=h;
        if(tail==NULL)
        {
            tail=newnode;
            newnode->next=newnode;
        }
        else
        {
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
}
void insert_at_beg(int h)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=h;
    if(tail==NULL)
    {
        tail=newnode;
        newnode->next=tail;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
    }
}
void insert_at_end(int h)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=h;
     if(tail==NULL)
    {
        tail=newnode;
        newnode->next=tail;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
}
void insert_at_pos(int h,int pos)
{   int count=1;
    if(tail==NULL)
    {
        insert_at_beg(h);
        return;
    }
    else
    {
        if(pos==1)
        {
        insert_at_beg(h);
            return;
        }
        struct node*newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=h;
        struct node*temp=tail->next;
        while(count<pos-1 && temp->next!=tail->next)
        {
            count++;
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        if(temp==tail)
        {
            tail=newnode;
        }
    }
}
void Deletion_at_beg()
{
    struct node *temp=tail->next;//Initialized temp
    if(tail==NULL)
        printf("\n No node found");
    else if(tail->next==tail)
    {
        tail=NULL;
        temp->next=NULL;//temp was not initialized
        free(temp);
    }
    /*else{
        if(tail==NULL)
            printf("\n No node found");
        else if(tail->next==tail)
        {
            tail=NULL;
            temp->next=NULL;//temp is not initialized
            free(temp);
        }*/
    //What is this!!
        else
        {
            tail->next=tail->next->next;
            temp->next=NULL;
            free(temp);
            //why tail=NULL ?
        }
}
void Deletion_at_end()
{
    struct node*temp,*temp2;
    if(tail==NULL)
        printf("\n No node found");
    else if(tail->next==tail)
    {
        temp=tail->next;//assigned temp
        tail=NULL;
        temp->next=NULL;//temp is not initialized
        free(temp);
    }
    else
    {
        temp=tail->next;
        while(temp->next!=tail)
        {
            temp=temp->next;
        }
        temp->next=tail->next;
        tail->next=NULL;//what is this!!
        temp2=tail;
        tail=temp;
        free(temp2);
    }   
}
void Deletion_at_pos(int pos)
{
    struct node*temp,*temp2;
    int count=1;
    if(tail==NULL)
    {
        printf("\n No node to delete");
    }
    else
    {
        if(pos==1)
        {
           Deletion_at_beg();
           return; 
        }
        else
        {
            temp=tail->next;
            while(count<pos-1 && temp->next!=tail)
            {
                temp=temp->next;
                count++;
            }
            temp2=temp->next;
            temp->next=temp2->next;
            temp2->next=NULL;
                if(temp2==tail)
                    tail=temp;
            free(temp2);
        }
}
}
void display()
{
    if(tail==NULL)
    {
        printf("\n nothing to display");
        return;
    }
    struct node*temp=tail->next;
    do
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }while(temp!=tail->next);
    //No need to print NULL as there is no NULL in CSLL
}
int main()
{
    int a,i,m,n,ch;
    printf("enter how many nodes you want:");
    scanf("%d",&a);
    for(i=1;i<=a;i++)
    {
        printf("enter data of the node:");
        scanf("%d",&m);
        creat_csll(m);
    }
    while(1)
    {
        int y,x,z;
    printf("\t 1.Inserton at beg\n\t 2.Insert at end\n\t 3.Insert at any pos\n\t 4.Deletion at beg\n\t 5.Deletion at end\n\t 6.Deletion at any pos\n\t 7.Display\n\t 8.exit\n\t ");
    printf("enter a option:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("enter a data:");
            scanf("%d",&y);
            insert_at_beg(y);
            break;
        case 2:
            printf("enter a data:");
            scanf("%d",&y);
            insert_at_end(y);
            break;
        case 3:
            printf("enter a data:");
            scanf("%d",&y);
            printf("enter a position:");
            scanf("%d",&x);
            insert_at_pos(y,x);
            break;
        case 4:
            Deletion_at_beg();
            break;
        case 5:
            Deletion_at_end();
            break;
        case 6:
            printf("enter a position:");
            scanf("%d",&z);
            Deletion_at_pos(z);
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Invalid Option");
            break;
    }
}
    return 0;
}