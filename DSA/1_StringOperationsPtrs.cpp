/******************************************************************************

String Operations with Pointers.
1 Length
2 Copy
3 Concatenate
4 Compare
5 Reverse

*******************************************************************************/

//Checked by PRR Mam

#include <iostream>
using namespace std;

int length(char*);
void copy(char*,char*);
void concat(char*,char*,char*);
int compare(char*,char*);
void reverse(char*);

int main()
{
	int x=0,ain=0,bin=0;
    char stra[80],*p;
    int len,comp;
    char strb[80],strc[160],rev[80];
    do
    {
		cout<<"\n\n\nThe String Operations are as follows. Choose any one:-\n1:Length\n2:Copy\n3:Concatenate\n4:Compare\n5:Reverse\n6:Exit.\n\nYour Choice : ";
		cin>>x;
		switch(x)
		{
			case 1:
			cout<<"\nEnter String A :";
			cin>>stra;
			len=length(stra);
			cout<<"\nThe length of String A is : "<<len;
			break;
			case 2:
			cout<<"\nEnter String A :";
			cin>>stra;
			copy(stra,strb);
			cout<<"\nString B : "<<strb;
			break;
			case 3:
			cout<<"\nEnter String A :";
			cin>>stra;
			cout<<"\nEnter String B :";
			cin>>strb;
			concat(stra,strb,strc);
			cout<<"\nString C : "<<strc;
			break;
			case 4:
			cout<<"\nEnter String A :";
			cin>>stra;
			cout<<"\nEnter String B :";
			cin>>strb;
			comp=compare(stra,strb);
			if(comp==0)
			    cout<<"\nThe two strings are equal.";
			else
		    	cout<<"\nThe two strings arent equal.";
			break;
			case 5:
			cout<<"\nEnter String A :";
			cin>>stra;
		    reverse(stra);
			cout<<"\nReversed String A is : "<<stra;
			break;
			case 6:
			break;
			default:
			cout<<"Invalid Choice Entered. Please Enter a Valid Choice.";
		}
    }while(x!=6);
    return 0;
}

int length(char *a)
{
    int i=0;
    while(*(a+i)!='\0')
    {
        i++;
    }
    return(i);
}
void copy(char *a,char *b)
{
    int i=0;
    while(*(a+i)!='\0')
    {
        *(b+i)=*(a+i);
        i++;
    }
    *(b+i)='\0';
}
void concat(char *a,char *b,char *c)
{
    int i=0,j;
    while(*(a+i)!='\0')
    {
        *(c+i)=*(a+i);
        i++;
    }
    j=0;
    while(*(b+j)!='\0')
    {
        *(c+i)=*(b+j);
        i++;
        j++;
    }
    *(c+i)='\0';
}
int compare(char *a,char *b)
{
    int flag=0,i=0;
    while(*(a+i)==*(b+i) && *(a+i)!='\0' && *(b+i)!='\0')
    {
        i++;
    }
    if(*(a+i)==*(b+i))
        flag=0;
    else
        flag=1;

    return(flag);
}
void reverse(char *a)
{
    int i=0,j;
    int l=0;
    char temp;
    while(*(a+l)!='\0')
    {
        l++;
    }
    l--;
    j=l;
    while(i<j)
    {
        temp=*(a+i);
        *(a+i)=*(a+j);
        *(a+j)=temp;
        i++;
        j--;
    }

}
