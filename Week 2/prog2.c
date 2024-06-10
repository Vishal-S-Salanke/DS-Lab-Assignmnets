#include<stdio.h>
#include<stdlib.h>
#include<math.h>


struct node 
{
	int coeff;
	int px;
	int py;
	struct node* next;
};

void create_node(int c, int p1, int p2,	struct node **temp);
void add_poly(struct node* poly1, struct node* poly2, struct node **temp);
void display(struct node  *node);

// Driver Code
int main()
{
	struct node *poly1 = NULL;
	struct node *poly2 = NULL;
	struct node *store = NULL;
	create_node(3, 2, 2, &poly1);
	create_node(2, 1, 2, &poly1);
	create_node(3, 1, 1, &poly1);
	
	create_node(4, 2, 2, &poly2);
	create_node(3, 2, 1, &poly2);
	create_node(6, 1, 1, &poly2);
	
	add_poly(poly1, poly2, &store);
	printf("Polynomial 1\n");
	display(poly1);
	printf("Polynomial 2 \n");
	display(poly2);
	printf("Polynomial after addition\n");
	display(store);

	return 0;
}


// Function to dynamically create a node
void create_node(int c, int p1, int p2,	struct node **temp)
{
	
	struct node *r;
	struct node *z = *temp;
	r = (struct node*)malloc(sizeof(struct node));		
	r->coeff = c;
	r->px = p1;
	r->py = p2;
	if (z == NULL) 
	{
		(*temp) = r;
		(*temp)->next = (*temp);
	}
	else 
	{
		r->next = z->next;
		z->next = r;
		(*temp) = r;
	}
}

void add_poly(struct node* poly1, struct node* poly2, struct node** temp)
{
	struct node *start1 = poly1;
	struct node *start2 = poly2;
	poly1 = poly1->next;
	poly2 = poly2->next;
	while ((poly1 != start1 && poly2 != start2)) 
	{				
		struct node *r;
		struct node *z	= *temp;		
		r = (struct node*)malloc(sizeof(struct node));		
		r->coeff = 0;
		if (poly1->px > poly2->px) 
		{
			r->coeff = poly1->coeff;
			r->px = poly1->px;
			r->py = poly1->py;
			poly1 = poly1->next;
		}
		else if (poly1->px < poly2->px) 
		{
			r->coeff = poly2->coeff;
			r->px = poly2->px;
			r->py = poly2->py;
			poly2 = poly2->next;
		}
		else 
		{
			if (poly1->py > poly2->py) 
			{
				r->coeff = poly1->coeff;
				r->px = poly1->px;
				r->py = poly1->py;
				poly1 = poly1->next;
			}
			else if (poly1->py < poly2->py) 
			{
				r->coeff = poly2->coeff;
				r->px = poly2->px;
				r->py = poly2->py;
				poly2 = poly2->next;
			}
			else 
			{
				r->coeff = poly2->coeff	+ poly1->coeff;		
				r->px = poly1->px;
				r->py = poly1->py;
				poly1 = poly1->next;
				poly2 = poly2->next;
			}
		}
		if (z == NULL) 
		{
			(*temp) = r;
			(*temp)->next = (*temp);
		}
		else 
		{
			r->next = z->next;
			z->next = r;
			(*temp) = r;
		}
	}
	while (poly1 != start1 || poly2 != start2) 
	{			
		if (poly1 != start1) 
		{
			struct node *r;
			struct node *z = *temp;
			r = (struct node*)malloc(sizeof(struct node));
			r->coeff = poly1->coeff;
			r->px = poly1->px;
			r->py = poly1->py;
			poly1 = poly1->next;
			if (z == NULL) 
			{
				(*temp) = r;
				(*temp)->next = (*temp);
			}
			else 
			{
				r->next = z->next;
				z->next = r;
				(*temp) = r;
			}
		}
		if (poly2 != start2) 
		{
			struct node *r;
			struct node *z = *temp;
			r = (struct node*)malloc(sizeof(struct node));		
			z->coeff = poly2->coeff;
			z->px = poly2->px;
			z->py = poly2->py;
			poly2 = poly2->next;
			if (z == NULL) 
			{
				(*temp) = r;
				(*temp)->next = (*temp);
			}
			else 
			{
				r->next = z->next;
				z->next = r;
				(*temp) = r;
			}
		}
	}
	struct node *r;
	struct node *z = *temp;
	r = (struct node*)malloc(sizeof(struct node));	
	r->coeff = 0;
	if (start1->px > start2->px) 
	{
		r->coeff = start1->coeff;
		r->px = start1->px;
		r->py = start1->py;
	}
	else if (start1->px < start2->px) 
	{
		r->coeff = start2->coeff;
		r->px = start2->px;
		r->py = start2->py;
	}
	else {
		if (start1->py > start2->py) 
		{
			r->coeff = start1->coeff;
			r->px = start1->px;
			r->py = start1->py;
		}
		else if (start1->py < start2->py) 
		{
			r->coeff = start2->coeff;
			r->px = start2->px;
			r->py = poly2->py;
		}
		else {
			r->coeff = start2->coeff + start1->coeff;
			r->px = start1->px;
			r->py = start1->py;
		}
	}
	if (z == NULL) 
	{
		(*temp) = r;
		(*temp)->next = (*temp);
	}
	else 
	{
		r->next = z->next;
		z->next = r;
		(*temp) = r;
	}
}


// Display the circular linked list
void display(struct node  *node)
{
	struct node *start = node;
	node = node->next;
	while (node != start && node->coeff != 0) 
	{		
		// Print coefficient of current node	
		printf("%d",node->coeff);
		if (node->px != 0)
		printf("x^%d",node->px);	
		if(node->px != 0 && node->py != 0)
		printf(" * ");
		if (node->py != 0)
		printf("y^%d" ,node->py);
		if (node != start && node->next->coeff != 0) 
		{
			printf(" + ");
		}
		node = node->next;
	}
	printf("%d",node->coeff);
	if (node->px != 0)
	printf("x^%d" ,node->px);	
	if (node->py != 0)
	printf("y^%d" ,node->py);
	printf("\n\n");
}
