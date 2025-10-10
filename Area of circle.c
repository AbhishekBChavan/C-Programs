#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int r;
float area;
printf("enter radius of the circle");
scanf("%d",&r);
area=3.14*r*r;
printf("area of the circle%2f",area);
getch();
}