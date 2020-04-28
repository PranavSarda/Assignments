#include<iostream>
#include<stack>
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

/*
struct node* create()
{
	int d;
	cout<<"\nEnter the Data for the Node or enter 0 to nullify this node : ";
	cin>>d;
	if(d==0)
	return(NULL);
	struct node *nn;
	nn=new node;
	nn->data=d;
	cout<<"\nEnter the Left Node of "<<d<<" : ";
	nn->left=create();
	cout<<"\nEnter the Right Node of "<<d<<" : ";
	nn->right=create();
	return(nn);
}
*/

void inorder(struct node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(struct node *root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct node *root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

/*

stack<struct node*> s;

void inorder(struct node *root)
{
	struct node *current=NULL,*temp=NULL;
	current=root;
	while(true)
	{
		while(current!=NULL)
		{
			s.push(current);
			current=current->left;
		}
		if(current==NULL && s.empty()==0)
		{
			temp=s.top();
			s.pop();
			cout<<temp->data<<" ";
			current=temp->right;
		}
		if(current==NULL && s.empty()==1)
			break;
	}
}

void preorder(struct node *root)
{
	struct node *current=NULL,*temp=NULL;
	current=root;
	while(true)
	{
		while(current!=NULL)
		{
			s.push(current);
			cout<<current->data<<" ";
			current=current->left;
		}
		if(current==NULL && s.empty()==0)
		{
			temp=s.top();
			s.pop();
			//cout<<temp->data<<" ";  Inorder
			current=temp->right;
		}
		if(current==NULL && s.empty()==1)
			break;
	}
}

stack<struct node*> post;

void postorder(struct node *root)
{
	struct node *current=NULL,*temp=NULL;
	current=root;
	while(true)
	{
		while(current!=NULL)
		{
			s.push(current);
			if(current->left!=NULL && current->right!=NULL)
				post.push(current);
			//cout<<current->data<<" ";  Preorder
			current=current->left;
		}
		if(current==NULL && s.empty()==0)
		{
			temp=s.top();
			s.pop();
			//cout<<temp->data<<" ";  Inorder
			current=temp->right;
		}
		if(current==NULL && s.empty()==1)
			break;
	}
}
*/

int main()
{
	int ch=0,d;
	struct node *root=NULL;
	//root=create();
	do
	{
		cout<<"\n1:Insert Element.\n2:Inorder Traversal\n3:Preorder Traversal\n4:Postorder Traversal\n0:Exit\nEnter your Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 0:break;
			case 1:
				cout<<"\nEnter the Element : ";
				cin>>d;
				root=insert(root,d);
				break;
			case 2:
				cout<<"\n\nInorder(Recursive) Traversal of given BST : ";
				inorder(root);
				break;
			case 3:
				cout<<"\n\nPreorder(Recursive) Traversal of given BST : ";
				preorder(root);
				break;
			case 4:
				cout<<"\n\nPostorder(Recursive) Traversal of given BST : ";
				postorder(root);
				break;
			default:
				cout<<"\nPlease enter a Valid Choice.";
		}
	}while(ch!=0);
	return(0);
}
