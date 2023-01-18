#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	struct node *next;
};
struct node *head;
int count()
{
	int i=0;
	struct node *temp;	
	temp=head;
	while(temp!=NULL)

	{
		i++;
		temp=temp->next;
	}
	return i;
}
void display()
{
	cout<<endl;
	struct node *temp;
	temp=head;
	if(head==NULL)
	{
		cout<<"list is empty";
		return;
	}
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
	cout<<endl;
}
void insertAtBegin()
{
	struct node *newNode;
	newNode=(struct node *)malloc(sizeof(struct node));
	if(newNode==NULL)
	{
		cout<<"Memory Has Full";
		return;
	}
	int value;
	cout<<"Enter Value :";
	cin>>value;
	newNode->data=value;
	cout<<"\n"<<value<<" Added successfully\n";
	if(head==NULL)
	{
		newNode->next=NULL;
		head=newNode;
	}
	else{
		newNode->next=head;
		head=newNode;
	}
}
void insertAtEnd()
{
	struct node *newNode;
	newNode=(struct node *)malloc(sizeof(struct node));
	if(newNode==NULL)
	{
		cout<<"memory is full";
		return;
	}
	int value;
	cout<<"Enter value :";
	cin>>value;
	newNode->data=value;
	cout<<"\n"<<value<<" Added Successfully\n";
	newNode->next = NULL;
	if(head==NULL)
	{		
		head=newNode;
	}
	else{
		struct node *temp;
		temp=head;
		while(temp->next!=NULL)
		{
			temp = temp -> next;			
		}
		temp->next = newNode;
	}
	
}
void insertAtSpecificPosition()
{
	struct node *newNode,*temp;
	temp=head;
	newNode=(struct node *)malloc(sizeof(struct node));
	if(newNode==NULL)
	{
		cout<<"Out of memory";
		return;
	}
	
	int pos,value,i=1;
	cout<<"Enter Position:";
	cin>>pos;
	
	
	if(pos==1)
	{
	  insertAtBegin();
	  return;	
	}
	else if(pos==count()+1)
	{
		insertAtEnd();
		return;
	}
	else if(pos>count()+1 || pos<1)
	{
		cout<<"Error";
		return;
	}
	else{
		cout<<"Enter value you want to store:";
	     cin>>value;
		while(i<pos-1)
	{
		temp=temp->next;
		i++;
	}
		newNode->data=value;
		cout<<"\n"<<value<<" Added Successfully\n";
		newNode->next=temp->next;
		temp->next=newNode;
	}
}
void deleteFromBegin()
{
	struct node *temp=head;
	if(head==NULL)
	{
		cout<<"List is empty";
		return;
	}
	int value;
	value=head->data;
	cout<<"\n"<<value<<" deleted successfully\n";
	head=head->next;
	free(temp);
	
}
void deleteFromEnd()
{
	struct node *temp1=head,*temp2;
	if(head==NULL)
	{
		cout<<"List is empty";
		return;
	}
	if(head->next==NULL)
	{
		int value;
		value=head->data;
		cout<<"\n"<<value<<" deleted successfully\n";
		free(head);
		return;
	}
	while(temp1->next->next!=NULL)
	{
		temp1=temp1->next;
	}
	
	temp2=temp1->next;
	int value;
	value=temp2->data;
	cout<<"\n"<<value<<" deleted Successfully\n";
	temp1->next=NULL;
	free(temp2);
	
	
}
void deleteFromPos()
{
	struct node *temp1=head,*temp2;
	if(temp1==NULL)
	{
		cout<<"list is empty";
		return;
	}
	int pos;
	cout<<"Enter postion:";
	cin>>pos;
	if(pos==1)
	{
		deleteFromBegin();
		
	}
	else if(pos==count())
	{
		deleteFromEnd();
	}
	else if(pos<1||pos>count())
	{
		cout<<"Error";
	}
	else{
		int i=1;
		while(i<pos-1)
		{
			temp1=temp1->next;
			i++;
		}
		temp2=temp1->next;
		cout<<"\n"<<temp2->data<<" deleted Successfully\n";
		temp1->next=temp2->next;
		free(temp2);
		
	}
	
}

int main()
{
		int userType;
    
    cout<<"\nWelcome to the Linked List World\n";
   while(true)
   {
   	cout<<"\nPress 1 for insert At Beginning\nPress 2 for insert At End\npress 3 for insert At Specific position\npress 4 for delete from begin\npress 5 for delete from End\npress 6 for delete from specific position\nPress 7 for Display\nPress 8 for Exit\n";
    cin>>userType;
   	 switch(userType)
    {
    	case 1:
    	{
    		
    	    insertAtBegin();
    		break;
			}	
    	case 2:
    		{
    			insertAtEnd();
    			break;
			}
		case 3:
		    {
		    		insertAtSpecificPosition();
		    	    break;
				}	
		
		
		case 4:
			{
				deleteFromBegin();
		    	break;
			}
		case 5:
		      {
		      		deleteFromEnd();
			       break;
			  }
		case 6:
			{
				deleteFromPos();
				break;
			}
			case 7:
			
			{
			display();
			break;
			}
		case 8:
			return 0;
	}
   }
    
}
