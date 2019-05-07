#include<stdio.h>
#include<conio.h>
#include "malloc.h"
struct node
{
int data;
struct node *link;
};

void main()
{
int a=111,b=2,c=3,will,wish,num;
char ch;
struct node *ptr,*ptr2,*result,*temp;
void add(struct node **,int );
struct node * search(struct node *);
void display(struct node *);
void invert(struct node *);
void del(struct node *,int);
struct node * concat(struct node *,struct node *);
ptr=NULL;
ptr2=NULL;
result=NULL; //result for storing the result of concatenation
clrscr();
will=1;

while(will==1)
{
main:
clrscr();
textcolor(2);
gotoxy(10,4);
cprintf("main Menu ");
gotoxy(10,6);
cprintf("1: Add element");
gotoxy(10,8);
cprintf("2. Delete element");
gotoxy(10,10);
cprintf("3. Search element");
gotoxy(10,12);
cprintf("4: Linked List concatenation");
gotoxy(10,14);
cprintf("5. Invert linked list");
gotoxy(10,16);
cprintf("6. Display elements");
gotoxy(10,18);
cprintf("7. Exit");
gotoxy(10,20);
cprintf("   Please enter the choice : ");
scanf("%d",&wish);
switch(wish)
{
case 1: up:
  //	gotoxy(10,24);
	printf("                                                   ");
   //	gotoxy(10,24);
	printf("\nEnter the element you want to add   ");
	scanf("%d",&num);
	add(&ptr,num);
	display(ptr);
	break;
case 2:
	printf("\nEnter the element to delete ");
	scanf("%d",&num);
	del(ptr,num);
	break;
case 3:
	printf("\n Now demonstrating search ");
	temp = search(ptr);
	printf("\nAddress of first occurence is  %u ",temp);
	break;
case 4:
 /* Inputs given internally for demo only */
 printf(" \nNow demonstrating linked list concatenation  Press any key to continue...");
 add(&ptr2,2);
 add(&ptr2,4);
 add(&ptr2,6);
 getch();
 printf(" \n Displaying second Linked List ");
 display(ptr2);
 getch();
 result = concat(ptr,ptr2);
 clrscr();
 printf(" \nNow Displaying the result of concatenation");
 display(result);
 getch();
 break;

case 5:
 printf("\n Inverting the list ... Press any key to continue...");
 invert(ptr);
 break;

case 6:
 display(ptr);
 break;
case 7:
 exit(0);
 break;

default:
 printf("  Illegal choice  ");
}
//gotoxy(10,24);
printf("\nDO you want to continue (Y/N) : ");
ch=getch();
if(ch=='y'||ch=='Y')
{
goto up;
}
else
{
goto main;
}
//scanf("%d",&will);

} //end of while
}

void add(struct node **q,int num)
{
struct node *temp;
temp = *q;
if(*q==NULL)
{
 *q=malloc(sizeof(struct node));
 temp = *q;
}
else
{
 while((temp->link)!=NULL)
{
 temp=temp->link;
}
temp->link = malloc(sizeof(struct node));
temp=temp->link;
}
temp->data = num;
temp->link  = NULL;
}

void display(struct node *pt)
{

while(pt!=NULL)
{
 printf(" Data : %d",pt->data);
 printf("  Link : %d",pt->link);
 pt=pt->link;
}
}

void invert(struct node *ptr)
{
struct node  *p,*q,*r;
p=ptr;
q=NULL;

while(p!=NULL)
{
 r=q;
 q=p;
 p=p->link;
 q->link=r;
}
ptr = q;
display(ptr);
}

// CONCATENATION OF LINKED LISTS

struct node * concat(struct node *p,struct node *q)
{
struct node *x,*r;


if (p==NULL)
r=q;

if (q==NULL)
r=p;
else
{
      x=p;
      r=x;
      while(x->link!=NULL)
	 x=x->link;
      x->link=q;
}
    return(r);
}


// SEARCHING AN ELEMENT IN THE LINKED LIST
// THIS FUNCTION FINDS THE FIRST OCCURENCE OF
// A DATA AND RETURNS A POINTER TO ITS ADDRESS

struct node * search(struct node *p)
{
struct node *temp;
int num;
temp = p;
printf(" \n  Enter the data that you want to search    ");
scanf("%d",&num);
printf("   Link of temp %u", temp->link);
while(temp->link!=NULL)
	{
	printf("  In while ");
	if(temp->data == num)
	return(temp);
	temp=temp->link;
	}
return(NULL);
}



// DELETING DATA FROM THE LINKED LIST//

void del(struct node *p,int num)
{

struct node *temp,*x;
temp=p;
x= NULL;

while (temp->link !=NULL)
{
if(temp->data == num)
{
	if (x==NULL)
	{
	p = temp->link;
	free(temp);
	return;
	}
	else
	{
	x->link = temp->link;
	free(temp);
	return;
	}
}                  //end of outer if
x=temp;
temp=temp->link;
}	//end of while
printf("\n No such entry to delete ");
}	//end of fn.