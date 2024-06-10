#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char name[50];
    char phone_number[11];
    char address[150];
    char area[50];
    struct node *next,*prev;
};
typedef struct node *NODEPTR;

struct CustomerDetails
{
    NODEPTR head;
};
typedef struct CustomerDetails *CD;

NODEPTR new_node();
void insert_customer(NODEPTR *p);
void display(NODEPTR p);

void main()
{
    NODEPTR first;
    int ch;
    first=NULL;
    while(1)
    {
        printf("\n\nEnter 1 to insert details of the customer\nEnter any other number to continue\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            insert_customer(&first);
        }
        else
        {
            break;
        }
    }
    printf("\nEntered details of Customer are\n");
    display(first);
}

NODEPTR new_node()
{
    NODEPTR ne=(NODEPTR)malloc(sizeof(struct node));
    ne->prev=ne->next=NULL;
    printf("Enter the Customer Name: ");
    scanf("%s",ne->name);
    printf("Enter the Phone No: ");
    scanf("%s",ne->phone_number);
    printf("Enter the Address: ");
    scanf("%s",ne->address);
    printf("Enter the Area: ");
    scanf("%s",ne->area);
    return ne;
}

void insert_customer(NODEPTR *p)
{
    NODEPTR temp,prev,pres;
    prev=NULL;
    pres=*p;
    temp=new_node();
    while(pres!=NULL && strcmp(temp->name,pres->name)>0)
	{
		prev=pres;
		pres=pres->next;
	}
	if(pres!=NULL)
	{
		if(prev==NULL)
		{
			temp->next=pres;
			*p=temp;
		}
		else
		{
			prev->next=temp;
			temp->next=pres;
		}
	}
	else
	{
		if(prev==NULL)
		{
			*p=temp;
		}
		else
		{
			prev->next=temp;
			temp->next=NULL;
		}
	}
}

void display(NODEPTR p)
{
    if(p==NULL)
        printf("List is empty\n");
    else
    {
        while(p!=NULL)
        {
            printf("\nCustomer Name \t Phone Number \t Address \t Area\n");
            printf("\t%s\ts%s\t%s\t%s",p->name,p->phone_number,p->address,p->area);
            p=p->next;
        }
    }
}


