#include<stdio.h>
#include<string.h>
struct student{
    char name[10];
    int roll;
    float marks;
};
int main(){
    struct student s1;
    fflush(stdin);
    printf("Enter the name: ");
    gets(s1.name);
    printf("\n Enter the roll: ");
    scanf("%d",&s1.roll);
printf("\n enter the marks: ");
scanf("%f",&s1.marks);
printf("\n The name of the student is %s \n Roll no is: %d \n Marks obtained is:%f",s1.name,s1.roll,s1.marks);
}
