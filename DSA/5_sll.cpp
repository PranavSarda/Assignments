#include<iostream>
using namespace std;

void display(struct sllnode*);			//Done
struct sllnode* create(struct sllnode*);	//Done
struct sllnode* add_begin(struct sllnode*);	//Done
struct sllnode* add_end(struct sllnode*);	//Done
struct sllnode* add_pos(struct sllnode*);	//Done
struct sllnode* del_begin(struct sllnode*);	//Done
struct sllnode* del_end(struct sllnode*);	//Done
struct sllnode* del_pos(struct sllnode*);	//Done
struct sllnode* search(struct sllnode*);	//Done
struct sllnode* modify(struct sllnode*);	//Done

struct sllnode
{
	int rno;
	char name[80];
	struct sllnode* next;
};

int main()
{
	unsigned int i,x=0,n;
	struct sllnode *head,*res;
	head=NULL;
	cout<<"\nEnter the Number of Nodes you want to create : ";
	cin>>n;
	for(i=0;i<n;i++)
		head=create(head);
	do
	{
		cout<<"\n\nWhat Operation do you want to perform on the SLL?\n\n1 : Display the List\n2 : Add at Beginning.\n3 : Add at End\n4 : Add at Position.\n5 : Delete at Beginning.\n6 : Delete at End.\n7 : Delete at Position.\n8 : Search for a Record.\n9 : Modify a Record.\n0 : Exit.\n\nEnter your Choice : ";
		cin>>x;
		switch(x)
		{
			case 0 : return 0;
			case 1 : display(head);break;
			case 2 : head=add_begin(head);break;
			case 3 : head=add_end(head);break;
			case 4 : head=add_pos(head);break;
			case 5 : head=del_begin(head);break;
			case 6 : head=del_end(head);break;
			case 7 : head=del_pos(head);break;
			case 8 : 
				res=search(head);
				if(res==NULL)
					cout<<"\nNode not found\n";
				else
					cout<<"\nNode Found :- \n Roll No. : "<<res->rno<<"\nName : "<<res->name<<endl;
				break;
			case 9 : head=modify(head);break;
			default : cout<<"\nPlease Enter a Valid Choice.\n";break;
		}
	}while(x!=0);
	return(0);
}

struct sllnode* create(struct sllnode* head)
{
	struct sllnode* nn;
	nn=new(struct sllnode);
	cout<<"\nEnter the Roll No. : ";
	cin>>nn->rno;
	cout<<"\nEnter the Name : ";
	cin>>nn->name;
	nn->next=NULL;
	if(head==NULL)
		head=nn;
	else
	{
		struct sllnode *temp;
		temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=nn;
	}
	return(head);
}

void display(struct sllnode* head)
{
	struct sllnode* temp;
	cout<<"\nThe Nodes are :-\nRoll No.\tName";
	temp=head;
	while(temp!=NULL)
	{
		cout<<endl<<temp->rno<<"\t"<<temp->name;
		temp=temp->next;
	}
	cout<<endl;
}

struct sllnode* add_begin(struct sllnode* head)
{
	struct sllnode* nn;
	nn=new(struct sllnode);
	cout<<"\nEnter the Roll No. : ";
	cin>>nn->rno;
	cout<<"\nEnter the Name : ";
	cin>>nn->name;
	nn->next=head;
	head=nn;
	return(head);
}

struct sllnode* add_end(struct sllnode* head)
{	
	struct sllnode* nn;
	nn=new(struct sllnode);
	cout<<"\nEnter the Roll No. : ";
	cin>>nn->rno;
	cout<<"\nEnter the Name : ";
	cin>>nn->name;
	nn->next=NULL;
	if(head==NULL)
		head=nn;
	else
	{
		struct sllnode *temp;
		temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=nn;
	}
	return(head);
}

struct sllnode* add_pos(struct sllnode* head)
{
	unsigned int i,pos;
	cout<<"\nEnter the Position you want to enter the new Node at (1,2,3,...) : ";
	cin>>pos;
	if(pos==1)
		head=add_begin(head);
	else
	{
		struct sllnode* nn;
		nn=new(struct sllnode);
		cout<<"\nEnter the Roll No. : ";
		cin>>nn->rno;
		cout<<"\nEnter the Name : ";
		cin>>nn->name;
		pos--;
		struct sllnode* temp;
		temp=head;
		for(i=1;i<pos && temp->next!=NULL;i++)
			temp=temp->next;
		nn->next=temp->next;
		temp->next=nn;
	}
	if(i<pos)
		cout<<"\nPosition out of Range. Adding at the End instead.\n";
	return(head);
}

struct sllnode* del_begin(struct sllnode* head)
{
	if(head==NULL)
		cout<<"\nList is Empty. Cannot Delete.\n";
	else
	{
		struct sllnode* temp;
		temp=head;
		head=temp->next;
		delete(temp);
		cout<<"\nNode Deleted.\n";
	}
	return(head);
}

struct sllnode* del_end(struct sllnode* head)
{
	if(head==NULL)
		cout<<"\nList is Empty. Cannot Delete.\n";
	else
	{
		struct sllnode *temp,*t;
		temp=head;
		while(temp->next!=NULL)
		{
			t=temp;
			temp=temp->next;
		}
		t->next=NULL;
		temp->next=NULL;
		delete(temp);
		cout<<"\nNode Deleted.\n";
	}
	return(head);
}

struct sllnode* del_pos(struct sllnode* head)
{
	unsigned int i,pos;
	if(head==NULL)
		cout<<"\nList is Empty. Cannot Delete Node.\n";
	else
	{
		cout<<"\nEnter the Position you want to delete the Node at (1,2,3,...) : ";
		cin>>pos;
		if(pos==1)
			head=del_begin(head);
		else
		{
			struct sllnode *temp,*t;
			temp=head;
			for(i=1;i<pos && temp->next!=NULL;i++)
			{
				t=temp;
				temp=temp->next;
			}
			if(i<pos)
			{
				cout<<"\nNode does not Exist.\n";
				return(head);
			}
			t->next=temp->next;
			delete(temp);
			cout<<"\nNode Deleted.\n";
		}
	}
	return(head);
}

struct sllnode* search(struct sllnode *head)
{
	unsigned int rno;
	struct sllnode *temp;
	temp=head;
	cout<<"\nEnter the Roll No. for the Record you want to search : ";
	cin>>rno;
	while(temp!=NULL && temp->rno!=rno)
		temp=temp->next;
	return(temp);
}

struct sllnode* search(struct sllnode *head,unsigned int rno)
{
	struct sllnode *temp;
	temp=head;
	/*  cout<<"\nEnter the Roll No. for the Record you want to search : ";
	cin>>rno;  */
	while(temp!=NULL && temp->rno!=rno)
		temp=temp->next;
	return(temp);
}


struct sllnode* modify(struct sllnode* head)
{
	unsigned int rno;
	struct sllnode *temp;
	cout<<"\nEnter the Roll No. that you want to Modify the Record of : ";
	cin>>rno;
	temp=search(head,rno);
	if(temp==NULL)
		cout<<"\nNode does not Exist. Cannot be Modified.\n";
	else
	{
		cout<<"\nEnter the Name : ";
		cin>>temp->name;
	}
	cout<<"\nThe Name has been Modified for given Roll Number.\n";
	return(head);
}
