#include<stdio.h>

void hanoi(char from, char to, char other, int n);
int main()
{
	int num;
	printf("\n Enter number of disks: ");
	scanf("%d", &num);
	printf("\n Towerof hanoi for %d number of disks: \n",num);
	hanoi('A','B','C',num);
	return 0;
}

void hanoi(char from, char to, char other, int n)
{
	if(n<=0)
	printf("\n Illegal number of disks");
	if(n==1)
	printf("\n Move disk from %c to %c \n\n",from,other);
	if(n>1)
	{
		hanoi(from,other,to,n-1);
		hanoi(from,to,other,1);
		hanoi(to,from,other,n-1);
	}
}

