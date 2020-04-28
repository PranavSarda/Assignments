#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int *a,posmin=0,n=0,i=0,j=0,k=0,temp=0,s,pos=-1,x;
	
	cout<<"\nEnter the number of Elements in the Array : ";
	cin>>n;
	a=(int*)malloc(n*sizeof(int));
	cout<<"Enter the Elements :- \n";
	for(k=0;k<n;k++)						//Input of elements
	{
		cin>>a[k];
	}
	do
	{	
		cout<<"\nWhat Operation do you want to perform?\n1:Display the Array.\n2:Sort in Ascending Order\n3:Sort in Descending Order\n4:Search for an Element\n0:Exit.\nYour Choice:";
		cin>>x;
		switch(x)
		{
			case 0:
			break;
			case 1:
			cout<<"\nThe Array is stored as : \n";
			for(k=0;k<n;k++)					//Output for each pass
				cout<<a[k]<<" ";
			break;
			
			case 2:
			cout<<endl<<"Passes:-"<<endl;
			for(k=0;k<n;k++)					//Output for each pass
			{
				cout<<a[k]<<" ";
			}
			for(i=0;i<n-1;i++)						//Outer Loop to put minimum element at i position
			{
				posmin=i;
				for(j=i+1;j<n;j++)					//Inner Loop to find smallest number in unsorted part
				{
					if(a[posmin]>a[j])
						posmin=j;
				}
				
				temp=a[i];							//Eachange the smallest element with i position
				a[i]=a[posmin];
				a[posmin]=temp;
				
				cout<<endl;
				for(k=0;k<n;k++)					//Output for each pass
				{
					cout<<a[k]<<" ";
				}
			}
			cout<<endl;
			break;

			case 3:
			cout<<"\nPasses :-\n";
			for(k=0;k<n;k++)
			{
				cout<<a[k]<<" ";
			}

			for(i=1;i<n;i++)						//Outer loop for current element position
			{
				j=i;
				while(j>0 && a[j]>a[j-1])			//Inner loop to move current element to its sorted position
				{
						temp=a[j];
						a[j]=a[j-1];
						a[j-1]=temp;
						j--;
				}
				
				cout<<endl;							//Output for each pass
				for(k=0;k<n;k++)
				{
					cout<<a[k]<<" ";
				}
			}
			cout<<endl;
			
			break;
			case 4:
			pos=-1;
			cout<<"Enter the Element to search.\n";
			cin>>s;
			for(i=0;i<n;i++)
				if(a[i]==s)
				{
					pos=i;
					break;
				}
			if(pos==-1)
				cout<<"\n\nElement not found.\n";
			else
				cout<<"\n\nElement found at "<<pos+1<<" position.\n";
			
			break;
			default:
			cout<<"\nInvalid Choice entered. Please enter a Valid Choice.";
		}
	}while(x!=0);
	
	return(0);
}
