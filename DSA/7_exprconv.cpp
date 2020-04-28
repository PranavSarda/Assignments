#include<iostream>
using namespace std;

char stack[50];
int top=-1;

void push(char c)
{
	top++;
	stack[top]=c;
}

char pop()
{
	char temp=stack[top];
	top--;
	return(temp);
}

int priority(char ch)
{
	switch(ch)
	{
		case '/':return 3;break;
		case '*':return 3;break;
		case '+':return 2;break;
		case '-':return 2;break;
		case '(':return 1;break;
	}
}

int main()
{
	int i,k,j;
	for(j=0;j<50;j++)
		stack[j]='0';
	char exp[50],postfix[50],temp;
	cout<<"\nEnter the Expression : ";
	cin>>exp;
	k=0;i=0;
	cout<<"\nExpression\t\t\tStack\t\t\t\tPostfix\n";
	while(exp[i]!='\0')
	{
		temp=exp[i];
		if((temp>='a' && temp<='z') || (temp>='A' && temp<='Z') || (temp>='0' && temp<='9'))
			postfix[k++]=temp;
		
		else if(temp=='(')
			push(temp);
		
		else if(temp==')')
		{
			while(stack[top]!='(')
				postfix[k++]=pop();
			temp=pop();
		}
		else
		{
			while(priority(stack[top])>=priority(temp))
				postfix[k++]=pop();
			push(temp);
		}
		
		for(j=0;j<=i;j++)
			cout<<exp[j];
		cout<<"\t\t\t\t";
		for(j=top;j>=0;j--)
			cout<<stack[j];
		cout<<"\t\t\t\t";
		for(j=0;j<k;j++)
			cout<<postfix[j];
		cout<<"\n";
		i++;

	}
	while(top>=0)
	{
		postfix[k++]=pop();
	}
	postfix[k]='\0';
	cout<<"\n\nThe Postfix Expression is : ";
	for(i=0;i<k;i++)
		cout<<postfix[i]<<" ";
	cout<<endl;
	return 0;	
}
