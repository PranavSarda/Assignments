#include<iostream>
#include<stdlib.h>
using namespace std;
int** sparseconv(int**,int,int,int);
int** simpletrans(int**);
int** fasttrans(int**);

int main()
{
	int r,c,**mat,**sparse,**trans,i,j,noz=0,curr,x=0;
	cout<<"\nEnter the Number of Rows and Columns :\n";
	cout<<"Rows : ";
	cin>>r;
	cout<<"Columns : ";
	cin>>c;
	mat=(int**)malloc(r*sizeof(int*));
	for(i=0;i<r;i++)
		*(mat+i)=(int*)malloc(c*sizeof(int));
	cout<<"\nEnter the Elements of the Matrix :-\n";
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cin>>curr;
			*(*(mat+i)+j)=curr;
			if(curr!=0)
				noz++;
		}
	}	
	
	//Here, do i need to malloc() **sparse in main()? It works this way too, but what problems could be created?
	sparse=sparseconv(mat,r,c,noz);   //Creates a Sparse Matrix stored in **spars
	cout<<endl<<"The Sparse Matrix is:-\n";
	for(i=0;i<=noz;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<sparse[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	do
	{
		//Even here havent allocated memory to **trans explicitly, still works. Any possible problems due to this?
		cout<<"\nTranspose Types:-\n1:Simple Transpose\n2:Fast Transpose\n3:Exit\nYour Choice:";
		cin>>x;
		switch(x)
		{
			case 1:
			trans=simpletrans(sparse);
			cout<<endl<<"The Transpose Sparse Matrix is:-\n";
			for(i=0;i<=noz;i++)
			{
				for(j=0;j<3;j++)
				{
					cout<<trans[i][j]<<"\t";
				}
				cout<<endl;
			}
			break;
			case 2:
			trans=fasttrans(sparse);
			cout<<endl<<"The Transpose Sparse Matrix is:-\n";
			for(i=0;i<=noz;i++)
			{
				for(j=0;j<3;j++)
				{
					cout<<trans[i][j]<<"\t";
				}
				cout<<endl;
			}

			break;
			case 3:
			break;
			default:
			cout<<"\nInvalid Choice Entered. Please enter a valid Choice.";
		}
	}while(x!=3);
	
/*	cout<<endl<<"The Transpose Sparse Matrix is:-\n";
	for(i=0;i<=noz;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<trans[i][j]<<"\t";
		}
		cout<<endl;
	}
*/	
	
	return(0);
}

int** sparseconv(int** mat,int r,int c,int noz)
{
	int i,j,curr=1,**sparse;
	sparse=(int**)malloc((noz+1)*sizeof(int*));
	for(i=0;i<=noz;i++)
		*(sparse+i)=(int*)malloc(3*sizeof(int));
	curr=0;
	sparse[curr][0]=r;
	sparse[curr][1]=c;
	sparse[curr][2]=noz;
	curr=1;

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(mat[i][j]!=0)
			{
				sparse[curr][0]=i;
				sparse[curr][1]=j;
				sparse[curr][2]=mat[i][j];
				curr++;
			}
		}
	}

	return(sparse);
}

int** simpletrans(int** sparse)
{
	int **trans,csearch=0,r,c,noz,curr,i;
	r=sparse[0][0];
	c=sparse[0][1];
	noz=sparse[0][2];
	trans=(int**)malloc((noz+1)*sizeof(int*));
	for(i=0;i<=noz;i++)
		*(trans+i)=(int*)malloc(3*sizeof(int));
	
	trans[0][0]=c;
	trans[0][1]=r;
	trans[0][2]=noz;
	curr=1;
	while(csearch<c)
	{
		for(i=1;i<=noz;i++)
		{
			if(sparse[i][1]==csearch)
			{
				trans[curr][0]=sparse[i][1];
				trans[curr][1]=sparse[i][0];
				trans[curr][2]=sparse[i][2];
				curr++;
			}
		}
		csearch++;
	}
	return(trans);
}

int** fasttrans(int** sparse)
{
	int **trans,*pos,*occur,r,c,noz,i,currpos;
	r=sparse[0][0];
	c=sparse[0][1];
	noz=sparse[0][2];
	
	trans=(int**)malloc((noz+1)*sizeof(int*));
	for(i=0;i<=noz;i++)
		*(trans+i)=(int*)malloc(3*sizeof(int));
	pos=(int*)malloc(c*sizeof(int));
	occur=(int*)calloc(c,sizeof(int));
	
	for(i=1;i<=noz;i++)
		occur[sparse[i][1]]++;
	
	pos[0]=1;
	for(i=1;i<c;i++)
		pos[i]=pos[i-1]+occur[i-1];
	
	trans[0][0]=c;
	trans[0][1]=r;
	trans[0][2]=noz;
	
	for(i=1;i<=noz;i++)
	{
		currpos=pos[sparse[i][1]];
		pos[sparse[i][1]]++;
		trans[currpos][0]=sparse[i][1];
		trans[currpos][1]=sparse[i][0];
		trans[currpos][2]=sparse[i][2];
	}
	
	return(trans);
}
