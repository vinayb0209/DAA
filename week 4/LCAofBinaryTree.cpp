#include<iostream>
#include<queue>
using namespace std;
struct Node{
	int val;
	Node* right;
	Node* left;
	Node(int v){
		val=v;
		left=right=NULL;
	}
};

Node* Build(){
	int value;
	cout<<"Enter Root";
	cin>>value;
	if(value==-1) return NULL;
	Node* root=new Node(value);
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* curr=q.front();
		q.pop();
		 
		int l,r;
		cout<<"Enter left child of "<<curr->val<<":\t";
		cin>>l;
		if(l!=-1) {
			curr->left=new Node(l);
			q.push(curr->left);
		}
		cout<<"Enter right child of "<<curr->val<<":\t";
		cin>>r;
		if(r!=-1){
			curr->right=new Node(r);
			q.push(curr->right);
		}
	}
	return root;
}
Node* LCA(Node* root, Node* p, Node* q){
	if(root==NULL|| root==p || root==q)
	return root;
	Node* left=LCA(root->left,p,q);
	Node* right=LCA(root->right,p,q);
	if(left && right)	
		return root;
	
	return left? left:right;
}
Node* findNode(Node* root, int val) {
    if (!root) 
		return nullptr;
    if (root->val==val) 
		return root;
    Node* left=findNode(root->left,val);
    	if(left) 
		return left;
    return findNode(root->right,val);
}
int main(){
	Node* root=Build();
	int p,q;
	cout<<"enter p:";
	cin>>p;
	cout<<"enter q:";
	cin>>q;
	
	
    Node* l = findNode(root, p);
    Node* r = findNode(root, q);

	if ( !l || !r) { 
		cout << "One or both nodes not found"<<endl; 
		return 0; 
	}
	cout<<"LCA:"<<LCA(root,l,r)->val<<endl;
	return 0;
}
 
 

