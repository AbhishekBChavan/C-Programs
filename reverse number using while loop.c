#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int n,rev=0;
printf("enter a number of reverse:\n");
scanf("%d",&n);
while(n!=0)
{
rev=rev*10;
rev=rev+n%10;
n=n/10;
}
printf("reverse of entered number is=%d\n",rev);
getch();
}