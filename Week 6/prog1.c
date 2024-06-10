#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char srn[20];
	struct node *left;
	struct node *right;
}node;

typedef struct tree
{
	node *root;
}tree;

void init(tree *p)
{
	p->root = NULL;
}

node *create(char *srn)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->left = NULL;
	temp->right = NULL;
	strcpy(temp->srn,srn);
	return temp;
}

void insert(tree *p,char *srn)
{
	if(p->root == NULL)
	{
	p->root = create(srn);
	}
	else
	{
		node *temp1 = p->root;
		node *temp2;
		while(temp1)
		{
			temp2 = temp1;
			if(strcmp(temp1->srn,srn) > 0)
			temp1 = temp1->left;
			else
			temp1 = temp1->right;

		}
		if(strcmp(temp2->srn,srn) > 0)
		temp2->left = create(srn);
		else
		temp2->right = create(srn);
	}
}

void inorder(node *p)
{
	if(!p) return;
	inorder(p->left);
	printf("%s\n",p->srn);
	inorder(p->right);
}

void display(tree *p)
{
	if(p->root == NULL)
	{
		printf("No data available");
		return;
	}
	inorder(p->root);
}

int inorder_search(node *p,char *srn)
{
	if(!p) return 0;
	if(strcmp(p->srn,srn) == 0) return 1;
	if(inorder_search(p->left,srn)) return 1;
	if(inorder_search(p->right,srn)) return 1;
	return 0;
}

void search(tree *p,char *srn)
{
	if(p->root == NULL)
	{
		printf("NOT FOUND\n");
		return;
	}
	else
	{
		if(inorder_search(p->root,srn)) printf("FOUND\n");
		else printf("NOT FOUND\n");
	}
}

int main()
{
	tree students;
	init(&students);
	while(1)
	{
		int choice;
		char srn[20];
		printf("\n1.insert\n2.display\n3.search\n4.exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
			printf("Enter the srn : ");
			scanf("%s",srn);
			insert(&students,srn);
			break;
			case 2:
			display(&students);
			break;
			case 3:
			printf("Enter the srn : ");
			scanf("%s",srn);
			search(&students,srn);
			break;
			default:
			exit(0);	
		}
	}
	return 0;
}