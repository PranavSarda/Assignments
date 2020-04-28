#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct stud
{
	int rno;
	char name[80];
}*st=NULL;

int create()
{
	int i=0,n;
	cout<<"\nEnter the Number of Records you want to create : ";
	cin>>n;
	st=(struct stud*)malloc(n*sizeof(struct stud));
	while(i<n)
	{
		cout<<"\nEnter the Roll No. of student "<<i+1<<" : ";
		cin>>(st+i)->rno;
		cout<<"Enter the Name of student "<<i+1<<" : ";
		cin>>(st+i)->name;
		i++;
	}
	return(n);
}

void display(int n)
{
	int i=0;
	cout<<"\n\nThe Records entered in the Database are : \n";
	while(i<n)
	{
		cout<<"\nThe Roll No. of student "<<i+1<<" is : ";
		cout<<(st+i)->rno;
		cout<<"\nThe Name of student "<<i+1<<" is : ";
		cout<<(st+i)->name;
		i++;
	}
	cout<<"\n";
}

void sort(int n)
{
	int temprno,i,j,ex=0;
	char tempname[80];
	for(i=0;i<n-1;i++)
	{
		ex=0;
		for(j=0;j<n-i-1;j++)
		{
			if((st+j)->rno > (st+j+1)->rno)
			{
				ex=1;
				temprno = (st+j)->rno;
				(st+j)->rno = (st+j+1)->rno;
				(st+j+1)->rno = temprno;

				strcpy(tempname,(st+j)->name);
				strcpy((st+j)->name,(st+j+1)->name);
				strcpy((st+j+1)->name,tempname);
			}
		}
		if(ex==0)
		break;
	}
}

void search(int n)
{
	int srno,res=0,beg=0,mid,end=n-1;
	mid=(beg+end)/2;
	cout<<"\n\nEnter the Roll No. you want to search for : "; //Would be illogical to search with name, but can be done with strcmp();
	cin>>srno;
	while(beg<=end && res==0)
	{
		mid=(beg+end)/2;
		if((st+mid)->rno==srno)
			res=1;
		else if((st+mid)->rno<srno)
			beg=mid+1;
		else
			end=mid-1;
	}
	if(res==0)
		cout<<"\n\nRecord with Desired Roll No. not found.\n";
	else
	{
		cout<<"\n\nRecord with Desired Roll No. found : ";
		cout<<"\nThe Roll No. of student is : ";
		cout<<(st+mid)->rno;
		cout<<"\nThe Name of student is : ";
		cout<<(st+mid)->name <<endl;
	}
}

int search(int n,int srno)
{
	int res=0,beg=0,mid,end=n-1;
	mid=(beg+end)/2;
/*	cout<<"\n\nEnter the Roll No. you want to search for : "; //Would be illogical to search with name, but can be done with strcmp();
	cin>>srno;
*/
	while(beg<=end && res==0)
	{
		mid=(beg+end)/2;
		if((st+mid)->rno==srno)
			res=1;
		else if((st+mid)->rno<srno)
			beg=mid+1;
		else
			end=mid-1;
	}
	if(res==0)
		return(-1);
	else
		return(mid);
}


int add(int n)
{
	int m,i,j,k,temprno;
	char tempname[80];
	cout<<"\nEnter the Number of Records you want to add : ";
	cin>>m;
	st=(struct stud*)realloc(st,(n+m)*sizeof(struct stud));
	cout<<"\nEnter the Records :\n";
	for(i=n;i<n+m;i++)
	{
		cout<<"\nEnter the Roll No. of student "<<i+1<<" : ";
		cin>>(st+i)->rno;
		cout<<"Enter the Name of student "<<i+1<<" : ";
		cin>>(st+i)->name;
	}
	i=n;
	while(i<(n+m))
	{
		k=i;
		j=k-1;
		while((st+k)->rno<(st+j)->rno)
		{
			temprno = (st+j)->rno;
			(st+j)->rno = (st+k)->rno;
			(st+k)->rno = temprno;

			strcpy(tempname,(st+j)->name);
			strcpy((st+j)->name,(st+k)->name);
			strcpy((st+k)->name,tempname);
			k--;
			j--;
		}
		i++;
	}
	return(n+m);
}

int del(int n)
{
	int delrno,sres,i,j;
	cout<<"\nEnter the Roll No. you want to delete the Record of : ";
	cin>>delrno;
	sort(n);
	sres=search(n,delrno);
	if(sres==-1)
	{
		cout<<"\nThe Roll No. was not found. Cannot Delete the Record.\n";
		return(n);
	}
	else
	{
		for(i=sres,j=sres+1;j<n;i++,j++)
		{
			(st+i)->rno=(st+j)->rno;
			strcpy((st+i)->name,(st+j)->name);
		}
		st=(struct stud*)realloc(st,(n-1)*sizeof(struct stud));
		return(n-1);
	}
}

void mod(int n)
{
	int modrno,sres;
	cout<<"\nEnter the Roll No. you want to modify the Record of : ";
	cin>>modrno;
	sort(n);
	sres=search(n,modrno);
	if(sres==-1)
	{
		cout<<"\nThe Roll No. was not found. Cannot Modify the Record.\n";
	}
	else
	{
		cout<<"\nEnter the Name of the Student : ";
		cin>>(st+sres)->name;
	}
}


int main()
{
	int n,x=0;
	n=create();
	sort(n);
	do
	{
		cout<<"\n\nChoose the Action you want to perform : \n1:Display Records\n2:Search a Record\n3:Add Records\n4:Modify a Record\n5:Delete a Record\n0:Exit\n\nYour Choice : ";
		cin>>x;
		switch(x)
		{
			case 0:
			break;
			case 1:
			display(n);
			break;
			case 2:
			search(n);
			break;
			case 3:
			n=add(n);
			cout<<"\nRecords Added.";
			break;
			case 4:
			mod(n);
			cout<<"\nRecord Modified.";
			break;
			case 5:
			n=del(n);
			cout<<"\nRecord Deleted.";
			break;
			default:
			cout<<"\nInvalid Choice Entered. Please Enter a Valid Choice.\n";
		}
	}while(x!=0);
	return 0;
}
