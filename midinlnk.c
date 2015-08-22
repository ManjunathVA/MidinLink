#include<stdio.h>
#include<malloc.h>
struct node
{
	struct node *link;
	int v;
};
typedef struct node *NODE;
NODE alloc()
{
	NODE p;
	p=(void *)malloc(sizeof(struct node));
	return p;
}
NODE inf(int i,NODE root)
{
	NODE t;
	t=alloc();
	t->link=NULL;
	t->v=i;
	if(root==NULL)
		return t;
	t->link=root;
	return t;
}
void midv(NODE root)
{
	NODE cur1,cur2,cur3;
	cur1=root;
	cur2=root;
	cur3=root;
	int flag=0;
	if(root==NULL)
	{
		printf("No elements\n");
	}
	while(cur1!=NULL)
	{
		cur1=cur1->link;
		if(cur1!=NULL)
		{
			cur1=cur1->link;
		}
		else if(cur1==NULL)
		{
			flag=1;
			cur3=cur2;
			break;
		}
		cur3=cur2;
		cur2=cur2->link;
	}
	if(cur1==NULL)
	{
		if(flag==1)
			printf("Mid value is %d\n\n",cur2->v);
		else
			printf("Mid values are %d and %d\n\n",cur3->v,cur2->v);
	}
}
void display(NODE root)
{
	NODE temp;
	temp=root;
	int j;
	if(root==NULL)
	{
		printf("Linked list is empty\n");
		return;
	}
	while(temp!=NULL)
	{
		printf("%d ",temp->v);
		temp=temp->link;
		if(temp==root)
			break;
	}
	printf("\n");
}
void main()
{
	NODE root=NULL;
	int ch;
	int i;
	while(1)
	{
		printf("1:Insert front 2:Display 3:Exit 4:Mid\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter value\n");
					scanf("%d",&i);
					root=inf(i,root);
					break;
			case 2: display(root);
					break;
			case 3: exit(0);
			case 4: midv(root);
					break;
		}
	}
}