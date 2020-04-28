#include <iostream>
using namespace std;
struct node
{
    int coe,exp;
    struct node *next;
};
struct node *head1=NULL,*head2=NULL,*head3=NULL;

void duplicate()	//function to remove nodes with same exponent
{
	int del=1;
	struct node *temp1,*temp2,*t;
	temp1=head3;
	while(temp1->next!=head3 && del==1)
	{
		del=0;
		t=temp1;
		temp2=temp1->next;
		while(temp2!=head3)
		{
			if(temp1->exp==temp2->exp)
			{
				del=1;
				temp1->coe=temp1->coe + temp2->coe;
				t->next=temp2->next;
				//delete(temp2);
				temp2=temp2->next;
			}
			else
			{
				t=temp2;
				temp2=temp2->next;
			}
		}
		temp1=temp1->next;
	}
}

void create1(int coe,int exp) //function to create a node in the list
{
    struct node *n1;
    n1 = new node;
    n1->coe=coe;
    n1->exp=exp;
    if(head1==NULL)
    {
        head1=n1;
        n1->next=head1;
    }
    else
    {
        struct node *t;
        t=head1;
        while(t->next!=head1)
        {
            t=t->next;
        }
        t->next=n1;
        n1->next=head1;
    }
}
void create2(int coe,int exp) //function to create a node in the list
{
    struct node *n2;
    n2 = new node;
    n2->coe=coe;
    n2->exp=exp;
    if(head2==NULL)
    {
        head2=n2;
        n2->next=head2;
    }
    else
    {
        struct node *t;
        t=head2;
        while(t->next!=head2)
        {
            t=t->next;
        }
        t->next=n2;
        n2->next=head2;
    }
}
void create3(int coe,int exp) //function to create a node in the list
{
    struct node *n3;
    n3 = new node;
    n3->coe=coe;
    n3->exp=exp;
    if(head3==NULL)
    {
        head3=n3;
        n3->next=head3;
    }
    else
    {
        struct node *t;
        t=head3;
        while(t->next!=head3)
        {
            t=t->next;
        }
        t->next=n3;
        n3->next=head3;
    }
}
void add_poly()
{
    int c,e;
    struct node *temp1,*temp2,*temp3;
    temp1=head1;
    temp2=head2;
    temp3=head3;
    do{
         int ctr=0;
        do{
            
            if(temp2->exp==temp1->exp)
            {
                
                c=temp1->coe+temp2->coe;
                e=temp1->exp;
                create3(c,e);
                ctr=0;
                break;
            }
            ctr=1;
            temp2=temp2->next;
        }while(temp2!=head2);
        if(ctr==1)
        {
            c=temp1->coe;
            e=temp1->exp;
            create3(c,e);
        }
        temp2=head2;
        temp1=temp1->next;
    }while(temp1!=head1);
    duplicate();
}
void mul_poly()
{
    int c,e;
    struct node *temp1,*temp2,*temp3;
    temp1=head1;
    temp2=head2;
    temp3=head3;
    do{
        do{
            c=temp1->coe*temp2->coe;
            e=temp1->exp+temp2->exp;
            create3(c,e);
            temp2=temp2->next;
        }while(temp2!=head2);
        temp1=temp1->next;
    }while(temp1!=head1);
}
void display() //function to display the elements
{
    struct node *temp;
    int choice;
    cout<<"1. Polynomial 1\n2. Polynomial 2\n3. Result\n";
    cin>>choice;
    switch(choice)
    {
        case 1:
        temp=head1;
        do{
        cout<<" "<<temp->coe<<"x^"<<temp->exp<<" ";
        if(temp->next!=head1)
        cout<<"+";
        temp=temp->next;
      } while(temp!=head1);
         break;
         case 2:
         temp=head2;
         do{
           cout<<" "<<temp->coe<<"x^"<<temp->exp<<" ";
           if(temp->next!=head2)
           cout<<"+";
           temp=temp->next;
         } while(temp!=head2);
         break;
         case 3:
	 duplicate();
         temp=head3;
       do{
         cout<<" "<<temp->coe<<"x^"<<temp->exp<<" ";
         if(temp->next!=head3)
         cout<<"+";
         temp=temp->next;
       } while(temp!=head3);
         break;
         default :
         cout<<"Invalid Choice\n";
         break;
    }
}
void accept() //function to accept the polynomial
{
         int i,num1,num2;
                 cout<<"Number of elements in polynomial : ";
                 cin>>num1;
                 cout<<"Enter polynomial : \n";
                 for(i=0;i<num1;i++)
                 {
                     int coe,exp;
                     cout<<i+1<<" Coefficient : ";
                     cin>>coe;
                     cout<<i+1<<" Exponential : ";
                     cin>>exp;
                     create1(coe,exp);
                 }
                 cout<<"Number of elements in polynomial : ";
                 cin>>num2;
                 cout<<"Enter polynomial\n";
                 for(i=0;i<num2;i++)
                 {
                     int coe,exp;
                     cout<<i+1<<" coefficient : ";
                     cin>>coe;
                     cout<<i+1<<" Exponential : ";
                     cin>>exp;
                     create2(coe,exp);
                 }
}
int main()
{
    int sw=0;
    while(sw!=5)
    {
        cout<<"\n1. Write polynomial\n2. Display\n3. Add\n4. Multiply\n5. Exit\n";
        cin>>sw;
        switch(sw)
        {
         case 1:
         accept();
         break;
         case 2:
         display();
         break;
         case 3:
         add_poly();
         break;
         case 4:
         mul_poly();
         break;
         case 5:
         cout<<"Exit . . .\n";
         break;
         default:
         cout<<"Invalid choice\n";
         break;
        }
    }
return 0;
} 

