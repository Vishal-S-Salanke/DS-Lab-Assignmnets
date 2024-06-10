#include<stdio.h>
#include<stdlib.h>
struct node
{
  char data;
  struct node *left;
  struct node *right;
};
struct node *create(char *exp);

int isoper(char ch);
int evaluate(struct node *t);
void push(struct  node **stk, int *t, struct node* temp);
struct node *pop(struct node **stk, int *t);
void preorder(struct node *t);
void inorder(struct node *t);
void postorder(struct node *t);

void main()
{
  struct node *root;
  char exp[100];
  root=NULL;
  
  printf("Enter the postfix form of the expression...");
  scanf("%s",exp);
  
  root=create(exp);
  printf("The infix expression........ \n");
  inorder(root);

  printf("\nThe prefix expression....... \n");
  preorder(root);

  printf("\nThe postfix expression......\n");
  postorder(root);

  printf("\nEvaluating the expression\n");
  int result = evaluate(root);
  printf("\nThe evaluation of the expression = %d\n",result);
  
}

int evaluate(struct node *t)
{
	int x;
	switch(t->data)
	{
		case '+': return(evaluate(t->left)+evaluate(t->right));
		case '-': return(evaluate(t->left)-evaluate(t->right));
		case '*': return(evaluate(t->left)*evaluate(t->right));
		case '/': return(evaluate(t->left)/evaluate(t->right));
		default : printf("%c=", t->data);
			scanf("%d",&x);
		return x;
	}
}

struct node *create(char *exp)
{
	struct node *temp;
	struct node *stk[100];
	
	int top=-1, i=0;
	char ch;
	while(exp[i]!='\0')
	{
		ch =  exp[i];
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=ch;
		temp->left=temp->right=NULL;
		if(isoper(ch))
		{
			temp->right=pop(stk,&top);
			temp->left=pop(stk,&top);
			push(stk,&top,temp);
		}
		else
		push(stk,&top,temp);
		i++;
	}
	return (pop(stk,&top));
}

int isoper(char ch)
{
    switch(ch)
    {
      case '+':
      case '-':
      case '*':
      case '/':return 1;
      default: return 0;
    }
}

void push(struct  node **stk, int *t, struct node* temp)
{
    ++*t;
    stk[*t]=temp;
}

struct node *pop(struct node **stk, int *t)
{
    struct node *temp;
     temp=stk[*t];
     --*t;
    return temp;
}

void preorder(struct node *t)
{
    if(t!=NULL)
    {
     printf("%c ",t->data);
     preorder(t->left);
     preorder(t->right);
   }
}

void postorder(struct node *t)
{
    if(t!=NULL)
    {
     
     postorder(t->left);
     postorder(t->right);
     printf("%c ",t->data);
   }
}

void inorder(struct node *t)
{
    if(t!=NULL)
    {
     inorder(t->left);
     printf("%c ",t->data);
     inorder(t->right);
   }
}