#include<stdio.h>
#include<conio.h>
int partition(int a[],int lb,int ub)
{
 int up,dn,l;
 int temp,pivot;
 up=ub;
 dn=lb+l;
 pivot=a[lb];
 do
  {
  while((a[dn]<pivot)&&(dn<=ub))
  {
	dn++;
	while((a[up]>pivot)&&(up>lb))
	{
		up--;
		if(dn<up)
		{
			temp=a[dn];
			a[dn]=a[up];
			a[up]=temp;

		}
  }      }
 }while(dn<up);
  /*interchange pivot&a[up]*/
  a[lb] = a[up];
  a[up] = pivot;
  return up;
}
void Quicksort(int a [],int lb, int ub)
{
 int j;
 if(lb<ub)
  {
   j=partition(a,lb,ub);
   Quicksort(a,lb,j-1);
   Quicksort(a,j+1,ub);
  }
}
/* main function */
void main()
{
int a[10],i,n;
clrscr();
printf("\nhow many numbers:");
scanf("%d",&n);
printf("\n enter the unsorted numbers:");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
Quicksort(a,0,n-1);
printf("\n the sorted list is:");
for(i=0;i<n;i++)
printf("%d \t",a[i]);
getch();
}