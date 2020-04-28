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

queue<struct node*> q;

int leveldisp(struct node* root)
{
	int s,i,l=0;
	struct node *current=NULL;
	q.push(root);
	cout<<endl;
	while(q.empty()==0)
	{
		l++;
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
	return(l);
}

void inorder(struct node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
/*
void leaf(struct node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	
	if(root->left==NULL && root->right==NULL)
		cout<<root->data<<" ";
	
	inorder(root->right);
}
*/

void leaf(struct node* root)
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
			if(current->left==NULL && current->right==NULL)
				cout<<current->data<<" ";
			q.pop();
			if(current->left!=NULL)
				q.push(current->left);
			if(current->right!=NULL)
				q.push(current->right);
		}
	}
}


int main()
{
	int ch=0,d,level;
	struct node *root=NULL,*res=NULL;
	do
	{
		cout<<"\n1:Insert Element.\n2:Display Tree Height.\n3:Display Nodes.\n4:Display Leaf Nodes.\n0:Exit\nEnter your Choice : ";
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
				cout<<"\nLevel-Wise the Tree is : ";
				level=leveldisp(root);
				cout<<"\nThe height of the Tree is : "<<level<<endl;
				break;
			case 3:
				cout<<"\nThe Nodes of the Tree are : ";
				inorder(root);
				break;
			case 4:
				cout<<"\nThe Leaf Nodes of the Tree are : ";
				leaf(root);
				break;
			default:
				cout<<"\nPlease enter a Valid Choice.";
				break;
		}
	}while(ch!=0);
	
	return 0;
}
