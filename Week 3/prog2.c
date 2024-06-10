#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Department
{
    char name[50];
    int number;
};
typedef struct Department *DP;

struct Node
{
    char ssn[15];
    char name[100];
    DP department;
    char designation[50];
    int salary;
    char phone_number[11];
    int age;
    struct Node *next, *prev;
};
typedef struct Node *NODEPTR;

NODEPTR new_node();
void insert_Employee(NODEPTR *p);
void display(NODEPTR p);
void display_dp(NODEPTR p,int *dp);
void delete_front(NODEPTR *p);
void deletes(NODEPTR *first,int pos);

void main()
{
    NODEPTR first,p,q;
    int ch,ch1,dp,n=1,i=1,key=58,po;
    first=NULL;
    while(1)
    {
        printf("\n\nEnter 1 to insert details of the customer\nEnter any other number to continue\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            insert_Employee(&first);
        }
        else
        {
            break;
        }
    }
    printf("\nThe Details of the Employees before deleting the details of the Employees having age above 58\n");
    display(first);
    printf("\nThe Details of the Employees after deleting the details of the Employees having age above 58\n");
    p=first;
    while(p->next!=NULL)
    {
        p=p->next;
        n++;
    }
    printf("\nNumber of Employees: %d\n",n);
    q=first;
    while(i<=n)
    {
        if(q->age > key)
        {
            deletes(&first,i);
            q=q->next;
            i++;
        }
        else
        {
            q=q->next;
            i++;
        }
    }
    display(first);
    while(1)
    {
        printf("\nEnter 1 to view the Employees of a particular department\nEnter any other number to exit\n");
        scanf("%d",&ch1);
        if(ch1==1)
        {
            printf("Enter the Department No: ");
            scanf("%d",&dp);
            getchar();
            printf("The details of Employees of Department %d\n",dp);
            display_dp(first,&dp);
        }
        else
        {
            break;
        }
    }
}

NODEPTR new_node()
{
    NODEPTR ne=(NODEPTR)malloc(sizeof(struct Node));
    int i,phone;
    ne->prev=ne->next=NULL;
    char HR[]="HR";
    char IT[]="IT";
    char Ac[]="Accounts";
    char BP[]="BPO";
    printf("\nEnter the SSN: ");
    scanf("%s",ne->ssn);
    printf("Enter the Name: ");
    scanf("%s",ne->name);
    ne->department=(DP)malloc(sizeof(struct Department));
    printf("Enter Department No 1:HR 2:IT 3:Accounts 4:BPO\n");
    printf("Enter the Department number: ");
    scanf("%d",&ne->department->number);
    switch(ne->department->number)
    {
        case 1: for(i=0;i<=1;i++)
                {
                    ne->department->name[i]=HR[i];
                }
                break;
        case 2: for(i=0;i<=1;i++)
                {
                    ne->department->name[i]=IT[i];
                }
                break;
        case 3: for(i=0;i<strlen(Ac)-1;i++)
                {
                    ne->department->name[i]=Ac[i];
                }
                break;
        case 4: for(i=0;i<=strlen(BP)-1;i++)
                {
                    ne->department->name[i]=BP[i];
                }
                break;
        default: printf("Invalid option\n");
                 break;
    }
    getchar();
    printf("Enter the Designation: ");
    scanf("%s",ne->designation);
    printf("Enter the salary: ");
    scanf("%d",&ne->salary);
    getchar();
    printf("Enter the Phone Number: ");
    scanf("%s",ne->phone_number);
    printf("Enter the age: ");
    scanf("%d",&ne->age);
    getchar();
    return ne;
}

void insert_Employee(NODEPTR *p)
{
    NODEPTR temp,q;
    temp=new_node();
    if(*p==NULL)
    {
        *p=temp;
    }
    else
    {
        q=*p;
		while(q->next!=NULL)
			q=q->next;
		q->next=temp;
		temp->prev=q;
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
            printf("Employee SSN: %s\n",p->ssn);
            printf("Employee Name: %s\n",p->name);
            printf("Phone Number: %s\n",p->phone_number);
            printf("Age: %d\n",p->age);
            printf("Designation: %s\n",p->designation);
            printf("Salary: %d\n",p->salary);
            printf("Department Name: %s\n",p->department->name);
            printf("Department Number: %d\n",p->department->number);
            p=p->next;
        }
    }
}

void display_dp(NODEPTR p,int *dp)
{
    if(p==NULL)
        printf("List is empty\n");
    else
    {
        while(p!=NULL)
        {
            if(p->department->number==*dp)
            {
                printf("\nEmployee SSN: %s\n",p->ssn);
                printf("Employee Name: %s\n",p->name);
                printf("Phone Number: %s\n",p->phone_number);
                printf("Age: %d\n",p->age);
                printf("Designation: %s\n",p->designation);
                printf("Salary: %d\n",p->salary);
                printf("Department Name: %s\n",p->department->name);
            }
            p=p->next;
        }
    }
}

void delete_front(NODEPTR *p)
{
	NODEPTR q;
	q=*p;
	if((q->prev==NULL)&&(q->next==NULL))
		*p=NULL;
	else
	{
		*p=q->next;
		(*p)->prev=NULL;
	}
	free(q);
}

void deletes(NODEPTR *first,int pos)
{
    NODEPTR pres,q;
    int i=1;
    pres=*first;
    q=*first;
    while(pres!=NULL && i<pos)
    {
        pres=pres->next;
        i++;
    }
    if(pres->prev==NULL)
    {
        delete_front(first);
    }
    else if(pres->next==NULL)
    {
        pres->prev->next=NULL;
        free(pres);
    }
    else
    {
        pres->prev->next=pres->next;
        pres->next->prev=pres->prev;
        free(pres);
    }
}