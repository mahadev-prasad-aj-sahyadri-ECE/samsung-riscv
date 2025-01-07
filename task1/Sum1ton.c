#include<stdio.h>
void main()
{
int sum=0,i,n;
printf("Enter the number: ");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
sum+=i;
}
printf("The sum of first %d numbers is %d\n",n,sum);
}