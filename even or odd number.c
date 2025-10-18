#include<stdio.h>
#include<conio.h>
void main()
{
    clrscr();
    int a;
    printf("enter any number");
    scanf("%d", &a);
    if(a%2==0)
    {
        printf("no is even");
    }
    else
    {
        printf("no is odd");
    }
    getch();
}