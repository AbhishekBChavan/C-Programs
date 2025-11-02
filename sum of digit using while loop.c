#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int n,a,sum=10;
printf("enter any number");
scanf("%d",&n);
while(n>0)
{
a=n%10;
sum=sum+a;
n=n/10;
}
printf("sum of digit of number=%d",sum);
getch();
}