#include<stdio.h>
#include<string.h>

void permute(char str[], int i, int n);
void swap(char *a, char *b);

int main()
{
	char str[20];
	printf("Enter any string: ");
	scanf("%s",str);
	printf("\n Using Recursion: \n");
	permute(str,0,strlen(str)-1);
	printf("\n\n");
	return 0;
}

void permute(char str[], int i, int n)
{
	int j;
	if(i==n)
	{
		for(j=0;j<=n;j++)
		printf("%c",str[j]);
		printf("\t");
	}
	else
	for(j=i;j<=n;j++)
	{
		swap(&str[i],&str[j]);
		permute(str,i+1,n);
		swap(&str[i],&str[j]);
	}
}

void swap(char *a, char *b)
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}


