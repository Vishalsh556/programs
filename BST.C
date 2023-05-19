// C program to demonstrate insert operation
// in binary search tree.

#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *left, *right;
};

void inordertraversal(struct node* root)
{
	if (root != NULL) {
		inordertraversal(root->left);
		printf("%d ", root->info);
		inordertraversal(root->right);
	}
}
void preordertraversal(struct node* root)
{
	if (root != NULL) {

		printf("%d ", root->info);
		 preordertraversal(root->left);
		 preordertraversal(root->right);
	}
}
void postordertraversal(struct node* root)
{
	if (root != NULL) {
		 postordertraversal(root->left);
		 postordertraversal(root->right);
		printf("%d ", root->info);

	}
}

struct node* insertion(struct node** root, int item)
{
	struct node *ptr,*parent,*loc;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->info=item;
	ptr->left=ptr->right=NULL;
	if (*root == NULL)
	*root=ptr;
	else
	{
	loc=*root;
	while(loc!=NULL)
	{
	parent=loc;
	if(item>loc->info)
	loc=loc->right;
	else
	loc=loc->left;
	}
	if(item>parent->info)
	parent->right=ptr;
	else
	parent->left=ptr;
	}

}

void main()
{
struct node *root=NULL;
int ch,item;
clrscr();
printf("\n1. insertion");
printf("\n2. inordertraversal");
printf("\n3. postordertraversal");
printf("\n4. preordertraversal");
printf("\n5. exit\n");
while(1)
{
printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("enter a itemn\n");
scanf("%d",&item);
insertion(&root,item);
break;
case 2:
inordertraversal(root);
break;
case 3:
postordertraversal(root);
break;
case 4:
preordertraversal(root);
break;
case 5:exit(0);
default:
printf("invalid choice");
}
getch();
}
}
