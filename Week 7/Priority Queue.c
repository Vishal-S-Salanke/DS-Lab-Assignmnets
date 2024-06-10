#include<stdio.h>
struct ele
{
	int data, pty;
};

void display(struct ele *h, int count);
void pqinsert(struct ele *h,struct ele key,int *count);
void heapify(struct ele *h, int n);

void main()
{
	struct ele pq[100],temp;
	int count=0,ch;
	while(1)
	{
		display(pq,count);
		printf("\n1: Insert\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the data and priority\n");
			scanf("%d%d",&temp.data,&temp.pty);
			pqinsert(pq,temp,&count);
			break;
		}
	}

}

void heapify(struct ele *h, int n)
{
		int i,j;
		struct ele key;
		j=0;
		key=h[j];
		i=2*j+1;
		while(i<=n)
		{
			if((i+1)<=n)
			{
				if(h[i+1].pty>h[i].pty)
				i++;		
			}
			if(key.pty>h[i].pty)
			{
				h[j]=h[i];
				j=i;
				i=2*j+1;

			}
			else
			break;
		}
		h[j]=key;
}

void display(struct ele *h, int count)
{
	int i=0;
	for(i=0;i<count;i++)
	{
		printf("Data = %d Priority = %d\n",h[i].data,h[i].pty);
		printf("\n");
	}
}

void pqinsert(struct ele *h,struct ele key,int *count)
{
	int i,j;
	i=*count;
	h[i]=key;
	++*count;
	j=(i-1)/2;
	while(i>0 && key.pty < h[j].pty)
	{
		h[i]=h[j];
		i=j;
		j=(i-1)/2;
	}	
	h[i]=key;
}