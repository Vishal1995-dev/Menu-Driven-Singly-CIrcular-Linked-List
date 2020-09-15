
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node * next;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

void Display(PNODE Head,PNODE Tail)
{
	if(Head==NULL)
	{
		return;
	}
	do
	{
		printf("%d\t",Head->data);
		Head=Head->next;
	}
	while(Head!=Tail->next);
}

int Count(PNODE Head,PNODE Tail)
{
	int i=0;
	if(Head==NULL)
	{
		return i;
	}
	do
	{
		i++;
		Head=Head->next;
	}
	while(Head!=Tail->next);
	return i;
}

void InsertFirst(PPNODE Head,PPNODE Tail,int value)
{
	PNODE newn = NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=value;
	newn->next=NULL;
	
	if(*Head==NULL)
	{
		*Head=newn;
		*Tail=newn;
	}
	else
	{
		newn->next=*Head;
		*Head=newn;
	}
	(*Tail)->next=*Head;
}

void InsertLast(PPNODE Head,PPNODE Tail,int value)
{
	PNODE newn = NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=value;
	newn->next=NULL;
	
	if(*Head==NULL)
	{
		*Head=newn;
		*Tail=newn;
	}
	else
	{
		(*Tail)->next=newn;
		*Tail=newn;
	}
	(*Tail)->next=*Head;
}

void InsertAtPos(PPNODE Head,PPNODE Tail,int value,int pos)
{
	int cnt=Count(*Head,*Tail);

	if(pos<1 || pos>cnt+1)
	{
		return;
	}
	if(pos==1)
	{
		InsertFirst(Head,Tail,value);
	}
	else if(pos==cnt+1)
	{
		InsertLast(Head,Tail,value);
	}
	else
	{
		int i=0;
		PNODE temp=*Head;
		PNODE newn = NULL;
		newn=(PNODE)malloc(sizeof(NODE));
		newn->data=value;
		newn->next=NULL;
		
		for(i=0;i<pos-2;i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
	}
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
	if(*Head==NULL)
	{
		return;
	}
	if(*Head==*Tail)
	{
		free(*Head);
		*Head=NULL;
		*Tail=NULL;
	}
	else
	{
		(*Tail)->next=(*Head)->next;
		free(*Head);
		*Head=(*Tail)->next;
	}
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
	if(*Head==NULL)
	{
		return;
	}
	if(*Head==*Tail)
	{
		free(*Head);
		*Head=NULL;
		*Tail=NULL;
	}
	else
	{
		PNODE temp=*Head;
		while(temp->next != *Tail)
        {
            temp = temp->next;
        }
        
        free(*Tail);
        *Tail = temp;
        (*Tail)->next = *Head;
	}
}

void DeleteAtPos(PPNODE Head,PPNODE Tail,int pos)
{
	int cnt=Count(*Head,*Tail);
	if(pos<1 || pos>cnt)
	{
		return;
	}
	if(pos==1)
	{
		DeleteFirst(Head,Tail);
	}
	else if(pos==cnt)
	{
		DeleteLast(Head,Tail);
	}
	else
	{
		int i=0;
		PNODE temp=*Head;
		for(i=0;i<pos-2;i++)
		{
			temp=temp->next;
		}
		
		PNODE temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
	}
}

int main()
{
	PNODE Head = NULL;
	PNODE Tail = NULL;
	
	int choice=1;
	int data=0;
	int pos=0;
	int ret=0;
	
	printf("Singly Circular Linked List\n");
	while(choice)
	{
		printf("-------------------\n");
		printf("1.Insert First\n2.Insert Last\n3.Insert At Position\n4.Display\n5.Count\n6.Delete First\n7.Delete Last\n8.Delete At Position\n0.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter data\n");
				scanf("%d",&data);
				InsertFirst(&Head,&Tail,data);
				break;
			case 2:
				printf("Enter data\n");
				scanf("%d",&data);
				InsertLast(&Head,&Tail,data);
				break;
			case 3:
				printf("Enter data\n");
				scanf("%d",&data);
				printf("Enter position\n");
				scanf("%d",&pos);
				InsertAtPos(&Head,&Tail,data,pos);
				break;
			case 4:
				printf("-------------------\n");
				Display(Head,Tail);
				printf("\n");
				break;
			case 5:
				ret=Count(Head,Tail);
				printf("Number of elements are : %d\n",ret);
				break;
			case 6:
				DeleteFirst(&Head,&Tail);
				break;
			case 7:
				DeleteLast(&Head,&Tail);
				break;
			case 8:
				printf("Enter position\n");
				scanf("%d",&pos);
				DeleteAtPos(&Head,&Tail,pos);
				break;
		}
	}
return 0;
}
