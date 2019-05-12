#include <stdio.h>
#include <stdlib.h>

//cicular double linked list structure
typedef struct list
{
	int data;
	struct list *next;
	struct list *prev;
}node;

void display(node *temp){
	//now temp1 is head basically
	node *temp1=temp;
	printf("The list is as follows :\n%d->",temp->data);
	temp=temp->next;
	//which not circle back to head node
	while(temp!=temp1)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp1->data);
	return;
}

int main(){
	node *head=NULL,*temp,*temp1;
	int choice;

	//building circular double linked list as input
	do
	{
		temp=(node *)malloc(sizeof(node));
		if(temp!=NULL)
		{
			printf("\nEnter the element in the list : ");
			scanf("%d",&temp->data);
			temp->next=head;
			if(head==NULL)
			{
				head=temp;
				temp->prev=head;
				temp->next=head;
			}
			else
			{
				temp1=head;
				while(temp1->next!=head)
				{
					temp1=temp1->next;
				}
				temp1->next=temp;
				temp->prev=temp1;
			}
		}
		else
		{
		printf("\nMemory not avilable...node allocation is not possible");
		}
		printf("\nIf you wish to add more data on the list enter 1 : ");
		scanf("%d",&choice);
	}while(choice==1);

	display(head);

	return 0;
}
