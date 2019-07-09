#include<iostream>
using namespace std;

struct node
{
	int val;
	node *left;
	node *right;
};

struct queue
{
	node *t[100];
	int front;
	int rear;
};

queue q;

void enqueue(node *n)
{
	q.t[q.rear++]=n;
}

node * dequeue()
{
	return (q.t[q.front++]);
}

void Insert(node *n, int x)
{
	if (x<n->val)
	{
		if (n->left==NULL)
		{
			node *temp=new node;
			temp->val=x;
			temp->left=NULL;
			temp->right=NULL;
			n->left=temp;
		}
		else
		{
			Insert(n->left, x);
		}
	}
	else
	{
		if (n->right==NULL)
		{
			node *temp=new node;
			temp->val=x;
			temp->left=NULL;
			temp->right=NULL;
			n->left=temp;
		}
		else
		{
			Insert(n->right, x);
		}
	}
}

int findMaxInLeftST(node *n)
{
	while(n->right!=NULL)
	{
		n=n->right;
	}
	return n->val;
}

void Remove(node *p, node *n, int x)
{
	if (n->val==x)
	{
		if (n->right==NULL && n->left==NULL)
		{
			if (x<p->val)
			{
				p->right=NULL;
			}
			else
			{
				p->left=NULL;
			}	
		}
		else if (n->right==NULL)
		{
			if (x<p->val)
			{
				p->right=n->left;
			}
			else
			{
				p->left=n->left;
			}
		}
		else if (n->left==NULL)
		{
			if (x<p->val)
			{
				p->right=n->right;
			}
			else
			{
				p->left=n->right;
			}
		}
		else
		{
			int y=findMaxInLeftST(n->left);
			n->val=y;
			Remove(n, n->right, y);
		}
	}
	else if (x<n->val)
	{
		Remove(n, n->left, x);
	}
	else
	{
		Remove(n, n->right, x);
	}
}

void BFT(node *n)
{
	if(n!=NULL)
	{
		cout<<n->val<<"  ";
		enqueue(n->left);
		enqueue(n->right);
		BFT(dequeue());
	}
}

void Pre(node *n)
{
	if (n!=NULL)
	{
		cout<<n->val<<"  ";
		Pre(n->left);
		Pre(n->right);
	}
}

void In(node *n)
{
	if (n!=NULL)
	{
		In(n->left);
		cout<<n->val<<"  ";
		In(n->right);
	}
}


void Post(node *n)
{
	if (n!=NULL)
	{
		Post(n->left);
		Post(n->right);
		cout<<n->val<<"  ";
	}
}

int main()
{
	q.front=0;
	q.rear=0;
	int value;
	int ch;
	node *root=new node;
}
