#include<iostream>
#include<queue>
using namespace std;

struct node
{
	int data;
	struct node *left,*right;
};

struct node* insert(struct node *root,int d)
{
	if(root==NULL)		//If Place Empty, add new node.
	{
		struct node *nn;
		nn=new node;
		nn->data=d;
		nn->left=NULL;
		nn->right=NULL;
		root=nn;
	}
	else if(root->data==d)
		cout<<"\nElement already present in BST.";
	else if(root->data>d)
		root->left=insert(root->left,d);	//Insert in Left SubTree
	else if(root->data<d)
		root->right=insert(root->right,d);	//Insert in Right SubTree
	return(root);
}

struct node* search(struct node* root,int d)
{
	if(root==NULL)
	{
		cout<<"\nElement Not Found.";
		return(NULL);
	}
	else if(d==root->data)
		return(root);
	else if(root->data<d)
		return(search(root->right,d));
	else
		return(search(root->left,d));
}

queue<struct node*> q;

void leveldisp(struct node* root)
{
	int s,i;
	struct node *current=NULL;
	q.push(root);
	cout<<endl;
	while(q.empty()==0)
	{
		s=q.size();
		for(i=0;i<s;i++)
		{
			current=q.front();
			cout<<current->data<<" ";
			q.pop();
			if(current->left!=NULL)
				q.push(current->left);
			if(current->right!=NULL)
				q.push(current->right);
		}
		cout<<endl;
	}
}

struct node* del(struct node *root,int d)
{
	if(root==NULL)
	{
		cout<<"\nNode does not Exist.";
		return(NULL);
	}
	else if(root->data < d)
		root->right=del(root->right,d);
	else if(root->data >d)
		root->left=del(root->left,d);
	else //if(root->data==d)	//Node to be deleted has been found
	{
		struct node *temp,*t;
		temp=root;
		cout<<"\nNode Deleted.";
		if(root->right==NULL && root->left==NULL)
			root=NULL;
		else if(root->left!=NULL && root->right==NULL)
			root=root->left;
		else if(root->left==NULL && root->right!=NULL)
			root=root->right;
		else //if(root->right!=NULL && root->left!=NULL)
			//Just pay attention to this case as it replaces the old node entirely
		{
			t=temp->left;
			if(t->right==NULL)
			{
				root=t;
				root->right=temp->right;
				
			}
			else
			{
				struct node *max;
				max=t->right;
				while(max->right!=NULL)
				{
					t=max;
					max=max->right;
				}
				if(max->left!=NULL)
					t->right=max->left;	//If max node has left subtree then add it to t->right
				else
					t->right=NULL;		//Else nullify t->right
				root=max;
				root->left=temp->left;		//We have placed a different node in the old node's
				root->right=temp->right;	//position. Hence we need this new node to point to old
								//left and right.
				max=NULL;
			}
		}
		delete(temp);		//Delete the previous 'root' node local to the function, that means the target node
	}
	return(root);		//Return the new replaced node in place of the deleted target node
}

int main()
{
	int ch=0,d;
	struct node *root=NULL,*res=NULL;
	do
	{
		cout<<"\n\nBinary Tree Operations:-\n1:Insert Element.\n2:Search Element.\n3:Display Tree Level-Wise.\n4:Delete a Node.\n0:Exit\nEnter your Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 0:break;
			case 1:
				cout<<"\nEnter the Element to add : ";
				cin>>d;
				root=insert(root,d);
				break;
			case 2:
				cout<<"\nEnter the Element to search : ";
				cin>>d;
				res=search(root,d);
				if(res!=NULL)
					cout<<"\nElement Found.";
				break;
			case 3:
				cout<<"\nLevel-Wise the Tree is : ";
				leveldisp(root);
				break;
			case 4:
				cout<<"\nEnter the Element to delete : ";
				cin>>d;
				root=del(root,d);
				break;
			default:
				cout<<"\nPlease enter a Valid Choice.";
				break;
		}
	}while(ch!=0);
	
	return 0;
}
