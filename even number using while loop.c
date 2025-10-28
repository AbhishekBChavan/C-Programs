#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int a;
printf("enter any number\n");
scanf("%d",&a);
while(a%2==0);
{
a++;
printf("%",a);
}
getch();
}