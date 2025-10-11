#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int b,h;
float area;
printf("enter the value of b and h");
scanf("%d %d", &b,&h);
area=(b*h)/2;
printf("area of triangle=%2f\n",area);
getch();
}