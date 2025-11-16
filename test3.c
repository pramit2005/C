#include<stdio.h>
int main()
{
    char a;
    printf("enter a char: ");
    scanf("%c",&a);
    switch(a)
    {
        case 'a':
            printf("\n %c is a vowel",a);
            break;
        case 'e':
            printf("\n %c is a vowel",a);
            break;
        case 'i':
            printf("\n %c is a vowel",a);
            break;
        case 'o':
            printf("\n %c is a vowel",a);
            break;
        case 'u':
            printf("\n %c is a vowel",a);
            break;
        default:
            printf("%c is a consonant",a);
            break;
    }
return 0;
}