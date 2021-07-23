#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node *left,*right;
};
Node *_prev=NULL;
Node *create()
{
	Node *newnode=new Node;
	int x;
	cout<<"Enter data(-1 for no data): ";
	cin>>x;
	if(x==-1)
	    return 0;
	newnode->data=x;
	cout<<"Enter left child of "<<x<<": \n";
	newnode->left=create();
	cout<<"Enter right child of "<<x<<": \n";
	newnode->right=create();
	return newnode;
}
Node * bToDLL(Node *root)
{
    if(root==NULL)
        return root;
    Node *head=bToDLL(root->left);
    if(_prev==NULL)
        head=root;
    else
    {
        root->left=_prev;
        _prev->right=root;
    }
    _prev=root;
    bToDLL(root->right);
    return head;
}
int main()
{
    Node *root=create();
    while(root!=NULL)
    {
        cout<<root->data<<" ";
        root=root->right;
    }
}