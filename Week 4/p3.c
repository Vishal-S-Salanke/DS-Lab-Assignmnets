#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *top);
void delete(struct node **top, int k);
void insert(struct node **top, int x);

int main()
{
    struct node *top;
    int choice,x,k;

    top=NULL;

    while(1)
    {
        printf("\nEnter you choice:\n1. Insert in stack\n2. Delete\n0. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: printf("Enter the value: ");
                    scanf("%d", &x);
                    insert(&top, x);
                    break;

            case 2: printf("Enter the value of K: ");
                    scanf("%d", &k);
                    delete(&top,k);
                    break;

            case 0: exit(0);
        }

        display(top);
    }
}

void insert(struct node **top, int x)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = *top;
    *top=temp;
}

void delete(struct node **top, int k)
{
    struct node *q, *p;
    q=*top;

    while((*top)->data < k)
    {
       *top=(*top)->next;
        free(q);
        q=*top;
    }

    p=q;
    q=q->next;

    while((q->next)!=NULL)
    {
        if((q->data) < k)
        {
            p->next = q->next;
            free(q);
            q=p->next;
        }
        else
        {
            p=q;
            q=q->next;
        }
    }

    if((q->next)== NULL && (q->data)<k)
    {
        p->next = NULL;
        free(q);
    }
}

void display(struct node *top)
{
    if(top == NULL)
    {
        printf("Stack list is empty \n");
    }
    else
    {
        while(top!=NULL)
        {
            printf("%d - ", top->data);
            top = top->next;
        }
    }
}