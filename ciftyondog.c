#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * next;
	struct node * prev;
};

struct node * start = NULL;
struct node * temp = NULL;
struct node * temp2 = NULL;
struct node * temp3 =NULL;


struct node * addbeg(struct node * start)
{
	int sayi;
	printf("hangi sayiyi basa eklmek istiyorsunuz?");
	scanf("%d",&sayi);
	struct node * newnode = (struct node * ) malloc(sizeof(struct node));
	newnode->data=sayi; 
	if(start==NULL)
	{
		start=newnode;
		start->next=NULL;
		start->prev=NULL;
	}	
	else
	{
		start->prev=newnode;
		newnode->next=start;
		newnode->prev=NULL;
		start=newnode;
	}
	return start;
}
struct node * addend(struct node * start)
{
	int sayi;
	printf("hangi sayiyi sona eklmek istiyorsunuz?");
	scanf("%d",&sayi);
	struct node * newnode = (struct node * ) malloc(sizeof(struct node));
	newnode->data=sayi;
	if(start==NULL)
	{
		start=newnode;
		start->next=NULL;
		start->prev=NULL;
	}
	else
	{
		temp=start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->next=NULL;
		newnode->prev=temp;
	}
	return start;
}

struct node * addafter(struct node *start)
{
	int sayi , aft;
	printf("hangi sayiyi eklmek istiyorsunuz?");
	scanf("%d",&sayi);
	printf("hangi sayidan sonra eklemek istiyorsunuz ?");
	scanf("%d",&aft);
	struct node * newnode = (struct node * ) malloc(sizeof(struct node));
	newnode->data=sayi;
	if(start==NULL)
	{
		start=addbeg(start);
	}
	else
	{
		temp=start;
		while(temp->data != aft)
		{
			temp=temp->next;
		}
		temp2=temp->next;
		temp->next=newnode;
		newnode->prev=temp;
		newnode->next=temp2;
	}
	return start;
	
}
struct node * delbeg(struct node * start)
{
	if(start==NULL)
	{
		printf("bastan silinecek bir eleman yok");
	}	
	else
	{
		if(start->next==NULL)
		{
			free(start);
			start=NULL;
		
		}
		else
		{
			temp=start->next;
			free(start);
			start=temp;
			start->prev=NULL;
		}

	}
	return start;
}
struct node * delend(struct node * start)
{
	if(start==NULL)
	{
		printf("sondan silinecek bir eleman yok");
	}
	else
	{
		if(start->next==NULL)
		{
			free(start);
			start=NULL;
		}
		else
		{
			temp=start;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp2=temp->prev;
			temp2->next=NULL;
			free(temp);
		
		}
		return start;
		
		
	}
}
struct node * del(struct node * start)
{
	int sayi;
	printf("listedeki hangi sayiyi silmek istiyorsunuz ?");
	scanf("%d", &sayi);
	if(start==NULL)
	{
		printf("listeden silinecek sayi yok");
	}
	else if(start->data==sayi)
	{
		start=delbeg(start);
	}
	else
	{	
	temp=start;
	while(temp->next->data!=sayi && temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	if(temp->next->next!=NULL)
	{
		temp2=temp->next->next;
		free(temp->next);
		temp->next=temp2;
		temp2->prev=temp;
	}
	else if(temp->next->next==NULL && temp->next->data==sayi)
	{
		start=delend(start);		
	}
	else 
	{
		printf("sectiginiz eleman listede yok.");
	}			
				
	}
	
	return start;
}

void display(struct node * start)
{
	if(start==NULL)
	{
		printf("yazdiracak eleman yok.");
	}
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}

}

int main()
{
	start=addbeg(start);
	start=addend(start);
	display(start);
	start=addafter(start);
	display(start);
	start=del(start);
	display(start);
}

