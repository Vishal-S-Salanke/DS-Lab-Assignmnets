#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	int data;
	struct node* l;
	struct node* r;
};
#define STACKSIZE 100

struct vnode
{
	struct node* n;
	int vleft;
	int vright;
};

struct stack
{
	int top;
	struct vnode* data[STACKSIZE];
};

void push(struct stack* st , struct vnode* d);
void pop(struct stack* st);
void bstInsertion(struct node* root , int d);
void bstIterativePostorder(struct node* root , struct stack* st);
void bstIterativePreorder(struct node* root , struct stack* st);
void bstIterativeInorder(struct node* root , struct stack* st);

int main()
{
	struct stack* st=(struct stack*)malloc(sizeof(struct stack));
	st->top=-1;
	struct node* root;
	root=(struct node*)malloc(sizeof(struct node));
	root->data = -1;
	while(true)
	{
		printf("1.BST Insertion \n");
		printf("2.Iterative Postorder Traversal \n");
		printf("3.Interative Preorder Traversal \n");
		printf("4.Interative Inorder Traversal \n");
		printf("\nEnter choice : ");
		int choice=0;
		scanf("%d",&choice);
		if(choice == 1)
		{
			int d;
			printf("\nEnter data to be inserted : ");
			scanf("%d",&d);
			bstInsertion(root , d);
		}
		else if(choice == 2)
		{
			printf("Postorder : \n");
			bstIterativePostorder(root , st);
			printf("\n");
		}
		else if(choice == 3)
		{
			printf("Preorder : \n");
			bstIterativePreorder(root,st);
			printf("\n");
		}
		else if(choice == 4)
		{
			printf("Inorder : \n");
			bstIterativeInorder(root , st);
			printf("\n");
		}
	}
}

void bstInsertion(struct node *root , int d)
{
	if(root->data < 0)
	{
		struct node *temp = (struct node*) malloc(sizeof(struct node));
		root->data = d;
		root->l = NULL;
		root->r = NULL;
		return;
	}
	else if(root->data > d)
	{
		if(root->l == NULL)
		{
			struct node* temp = (struct node*) malloc(sizeof(struct node));
			temp->data = d;
			temp->l = NULL;
			temp->r =NULL;
			root->l = temp;
			return;
		}
		else
		{
			bstInsertion(root->l,d);
		}
	}
	else
	{
		if(root->r == NULL)
		{
			struct node* temp = (struct node*) malloc(sizeof(struct node));
			temp->data = d;
			temp->l = NULL;
			temp->r =NULL;
			root->r = temp;
			return;
		}
		else
		{
			bstInsertion(root->r,d);
		}
	}
}

struct vnode* stackpeek(struct stack* st)
{
	return st->data[st->top];
}

void push(struct stack* st , struct vnode* d)
{
	if(st->top == STACKSIZE-1)
	{
		return;
	}
	else
	{
		(st->top)++;
		st->data[st->top]=d;
		return;
	}
}

void pop(struct stack* st)
{
	if(st->top==-1)
	{
		return;
	}
	else
	{
		(st->top)--;
	}
}

void bstIterativePostorder(struct node* root , struct stack* st)
{
	struct vnode* tempvnode = (struct vnode*)malloc(sizeof(struct vnode));
	tempvnode->n = root;
	tempvnode->vleft = 0;
	tempvnode->vright = 0;
	push(st , tempvnode);
	while(st->top != -1)
	{
		if(root->l != NULL && stackpeek(st)->vleft==0)
		{
			stackpeek(st)->vleft = 1;
			root= root->l;
			struct vnode* templnode = (struct vnode*)malloc(sizeof(struct vnode));
			templnode->n = root;
			templnode->vleft = 0;
			templnode->vright = 0;
			push(st , templnode);
			continue;
		}
		if(root->r != NULL && stackpeek(st)->vright == 0)
		{		
			stackpeek(st)->vright = 1;
			root = root->r;
			struct vnode* temprnode = (struct vnode*)malloc(sizeof(struct vnode));
			temprnode->n = root;
			temprnode->vleft = 0;
			temprnode-> vright = 0;
			push(st , temprnode);
			continue;
		}
		printf("%d->",root->data);
		pop(st);
		if(st->top != -1)
		{
			root = stackpeek(st)->n;
		}
	}
	return;
}

void bstIterativePreorder(struct node* root , struct stack* st)
{
	struct vnode* tempvnode = (struct vnode*)malloc(sizeof(struct vnode));
	tempvnode->n = root;
	push(st , tempvnode);
	while(st->top != -1)
	{
		root = stackpeek(st)->n;
		printf("%d ->",root->data);
		pop(st);
		if(root->r != NULL)
		{
			struct vnode* temprnode = (struct vnode*)malloc(sizeof(struct vnode));
			temprnode->n = root->r;
			push(st , temprnode);
		}
		if(root->l != NULL)
		{
			struct vnode* templnode = (struct vnode*)malloc(sizeof(struct vnode));
			templnode->n = root->l;
			push(st , templnode);
		}
	}
}

void bstIterativeInorder(struct node* root , struct stack* st)
{
	while(root != NULL)
	{
		while(root != NULL)
		{
			if(root->r != NULL)
			{
				struct vnode* temprnode = (struct vnode*)malloc(sizeof(struct vnode));
				temprnode->n = root->r;
				push(st , temprnode);
			}
			struct vnode* tempvnode = (struct vnode*)malloc(sizeof(struct vnode));
			tempvnode->n = root;
			push(st , tempvnode);
			root=root->l;
		}
		root = stackpeek(st)->n;
		pop(st);
		while(st->top != -1 && root->r == NULL)
		{
			printf("%d ->",root->data);
			root = stackpeek(st)->n;
			pop(st);
		}
		printf("%d ->" , root->data);
		if(st->top != -1)
		{
			root = stackpeek(st)->n;
			pop(st);
		}
		else
		{
			root = NULL;
		}
	}
}