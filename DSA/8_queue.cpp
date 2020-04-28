#include<iostream>
using namespace std;
#define N 5

struct queue
{
	int q[N];
	int front,rear;
};
struct queue p;


void enq(int ch)
{
	if((p.rear+1)%N==p.front)
	{
		cout<<"\nOrder Capacity Full. Cannot take more Orders.\n";
	}
	
	else if(p.front==-1)
	{
		p.front++;
		p.rear++;
	}
	else
		p.rear=(p.rear+1)%N;
	p.q[p.rear]=ch;
}

int deq()
{
	int ret;
	if(p.front==-1)
	{
		cout<<"\nNo Orders left to serve.\n";
		return 0;
	}
	else if(p.front==p.rear)
	{
		ret=p.q[p.front];
		p.front=-1;
		p.rear=-1;
	}
	else
	{
		ret=p.q[p.front];
		p.front=(p.front+1)%N;
	}
	return(ret);
}

int main()
{
	p.front=-1;
	p.rear=-1;
	int ch=0,pi;
	cout<<"\nWelcome to the Pizza Shop :-\n";
	do
	{
		cout<<"\n1:Place Order.\n2:Receive Order.\n0:Exit\nPlease Enter your Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 0:break;
			case 1:
				cout<<"\n1:Cheese.\n2:Onion\n3:Mushroom\n4:Pineapple\nEnter your Pizza : ";
				cin>>pi;
				enq(pi);
				break;
			case 2:
				pi=deq();
				switch(pi)
				{
					case 0:break;
					case 1:cout<<"\nCheese ";break;
					case 2:cout<<"\nOnion ";break;
					case 3:cout<<"\nMushroom ";break;
					case 4:cout<<"\nPineapple ";break;
				}
				if(pi!=0)
				cout<<"Pizza has been served.\n";break;
			default:
				cout<<"\nPlease Enter a Valid Choice.";break;
		}
		
	}while(ch!=0);
	
	return 0;
}
