#include<stdio.h>
#include<conio.h>
#define MAXSIZE 20
typedef struct
{
	int data[MAXSIZE];
	int top;
}STACK;
void initstack(STACK *ps)
{
 ps->top = -1;
 }
 void push(STACK *ps, int num)
{
ps-> data[++ps->top] =num;
}
int pop (STACK *ps)
{
return (ps->data[ps->top--]);
}
int isempty(STACK *ps)
{
return (ps-> top == -1);
}
int isfull(STACK *ps)
{
return(ps->top==MAXSIZE-1);
}
void main()
{
int n,choice;

STACK s1;
initstack(&s1);
do
{
printf("\n1:PUSH\n2:POP\n3:EXIT");
printf("\n enter your choice:");
scanf("%d",&choice);
switch(choice)
 {
  case 1: /* push */
     if(isfull(&s1))
     printf("\nstack overflow");
     else
     {
     printf("enter the element to be pushed");
     scanf("%d",&n);
     push(&s1,n);
     }
  break;
 case 2: /* pop */
 if(isempty(&s1))
 printf("\n stack underflow");
 else
  printf("the popped element is : %d",pop(&s1));
  break;
 }
 }
 while(choice !=3);
 getch();
 }

