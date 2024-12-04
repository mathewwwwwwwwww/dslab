#include<stdio.h>
#include<stdlib.h>
struct node
{
	 int data;
	struct node*next;
};
struct node*top=NULL;
void push()	
{
	int value;
	struct node*newNode=(struct node*)malloc(sizeof(struct node));
	if(!newNode)
	{
		printf("stack overflow\n");
		return;
	}
	else
	{
		printf("enter elements to push:");
		scanf("%d",&value);
		if(top==NULL)
		{
			newNode->data=value;
			newNode->next=NULL;
			top=newNode;
		}
		else
		{
			newNode->data=value;
			newNode->next=top;
			top=newNode;
		}
		printf("%d pushed on to the stack\n",value);
	}
}

void pop()
{
	if(top==NULL)
	{
		printf("stack overflow\n");
		return;
	}
	struct node *temp=top;
	top=(top)->next;
	printf("%d popped from the stack\n",temp->data);
	free(temp);
}
void display()
{
	if(top==NULL)
	{
	printf("stack is empty\n");
	}
	else
	{
	printf("stack elements:\n");
	struct node*temp=top;
	while(temp!=NULL)
		{
		printf("%d ->",temp->data);
		temp=temp->next;
		}
	}
}
void search()
{
	struct node*temp=top;
	int position=1,found=0,el;
 	if(top==NULL)
		{
		printf("stack is empty");
		}
 	else
		{
		printf("enter the value to search:\n");
		scanf("%d",&el);
		while(temp!=NULL)
 			{
			if(temp->data==el)
				{
				printf("%d found at the postition %d\n",el,position);
				found=1;
				break;
				}
			temp=temp->next;
			position++;
			}
        	if(found==0)
			{
			printf("%d not found in the stack\n",el);

			}
		}
}

int main()
{
	int choice,value;
	do
	{
		printf("chooose an operation :\n 1.push\n 2.pop\n 3.display\n 4.search\n 5.exit\n enter your choice :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2: 
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				search();
				break;
			case 5:
				printf("invalid choice.. please try again:\n");
		}
	}
	while(choice!=5);
	return 0;
}
