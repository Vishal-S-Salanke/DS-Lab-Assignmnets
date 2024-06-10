#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

struct student
{
	int sem;
	char name[25];
	char srn[20];
	int  DS,OS,SDS,DDCO,Python;
};


int main()
{
	struct student s[20], temp;
	int tot1=0,tot2=0,tot3=0,tot4=0,tot5=0;
	int avg1,avg2,avg3,avg4,avg5;
	int i,n,j;
	printf("Enter the number of students: ");
	scanf("%d",&n);

//take input from user
	printf("\n\t*Students Records*\n");
	for(i=0;i<n;i++)
	{
		printf("\n\nEnter Student Roll Number: ");
		scanf("%s",s[i].srn);
		printf("\nEnter Student name: ");
		scanf("%s",s[i].name);
		printf("\nEnter Semester: ");
		scanf("%d",&s[i].sem);
		printf("\nEnter DS marks: ");
		scanf("%d",&s[i].DS);
		printf("\nEnter OS marks: ");
		scanf("%d",&s[i].OS);
		printf("\nEnter SDS marks: ");
		scanf("%d",&s[i].SDS);
		printf("\nEnter DDCO marks: ");
		scanf("%d",&s[i].DDCO);
		printf("\nEnter Python marks: ");
		scanf("%d",&s[i].Python);
	}
	for(i=0;i<n;i++)
    {
      	for(j=i+1;j<n;j++)
		{
        	if(strcmp(s[i].srn,s[j].srn)>0)
			{
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
            }
        }
    }

//calculate average
	for(i=0; i<n; i++)
    {
       	tot1+=s[i].DS;
       	tot2+=s[i].OS;
       	tot3+=s[i].SDS;
       	tot4+=s[i].DDCO;
       	tot5+=s[i].Python;
	}
	printf("\n\nThe class average is as follows\n");
	avg1=tot1/n;
	avg2=tot2/n;
	avg3=tot3/n;
	avg4=tot4/n;
	avg5=tot5/n;
	printf("DS = %d\n",avg1);
	printf("OS = %d\n",avg2);
	printf("SDS = %d\n",avg3);
	printf("DDCO = %d\n",avg4);
	printf("Python = %d\n",avg5);
         
//Display result	 
	for(i=0;i<n;i++)
	{
		printf("\t\n\n*Students Records*\n");
		printf("\n==================================\n");
		printf("\nStudent's Roll no. :  %s", s[i].srn);
		printf("\nStudent's Name :  %s", s[i].name);
		printf("\nStudent's Sem :  %d", s[i].sem);
		printf("\nStudent's Marks of DS :  %d", s[i].DS);
		printf("\nStudent's Marks of OS :  %d", s[i].OS);
		printf("\nStudent's Marks of SDS :  %d", s[i].SDS);
		printf("\nStudent's Marks of DDCO :  %d", s[i].DDCO);
		printf("\nStudent's Marks of Python : %d", s[i].Python);
	}
	
	 
}



