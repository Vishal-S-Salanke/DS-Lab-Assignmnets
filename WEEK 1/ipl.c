#include<stdio.h>

struct cricket
{
	int runs, wickets;
	char name[25];
}player[50], t;

void main()
{
	int i, j, n;
	printf("Enter the number of cricket players: ");
	scanf("%d",&n);
	printf("\n Enter crickters information \n");
	for(i=0;i<n;i++)
	{
		printf("\nEnter Cricketer name: ");
		scanf("%s", player[i].name);
		printf("Enter Cricketer Runs: ");
		scanf("%d", &player[i].runs);
		printf("Enter Cricketer wickets: ");
		scanf("%d", &player[i].wickets);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(player[j].runs > player[j+1].runs)
			{
				t = player[j];
				player[j] = player[j+1];
				player[j+1] = t;
			}
		}	
	}
	printf("\n Crickter Runs Scored\n");
	printf("\nName\t\t Runs Scored\t\t Wickets \n");
	printf("-----------------------------------------------");
	for(i=0;i<n;i++)
	{
		printf("\n%s\t\t %d\t\t %d \n", player[i].name, player[i].runs, player[i].wickets);
		
	}
}
