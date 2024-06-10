#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};
typedef struct node *NODEPTR;

struct node  *new_node(int data);
struct node *insert(struct node *root,int data);
void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);
struct node *deleteNode(struct node *root, int data);

int main()
{
	struct node *root;
    int num,ch,de;
    root=NULL;
    while(1)
    {
        printf("\nEnter\n\n 1: Insert\n 2: Preorder\n 3: Inorder\n 4: Postorder\n5: Delete an element\n");
        printf("\nEnter your choice\n");
		scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the number: ");
                    scanf("%d",&num);
                    root=insert(root,num);
                    break;
            case 2: preorder(root);
                    printf("\n");
                    break;
            case 3: inorder(root);
                    printf("\n");
                    break;
            case 4: postorder(root);
                    printf("\n");
                    break;
            case 5: printf("Enter the number to be deleted: ");
                    scanf("%d",&de);
                    root=deleteNode(root,de);
                    break;
        }
    }
}

struct node  *new_node(int data)
{
    struct node *ne;
    ne=(NODEPTR)malloc(sizeof(struct node));
    ne->data=data;
    ne->left=ne->right=NULL;
    return ne;
}

struct node *insert(struct node *root,int data)
{
    struct node *temp;
    if(root==NULL)
    {
        temp=new_node(data);
        return temp;
    }
    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    return root;
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}

struct node* minValueNode(struct node *node)
{
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

struct node *deleteNode(struct node *root, int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else 
	{
        if (root->left == NULL) 
		{
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) 
		{
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
