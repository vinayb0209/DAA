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

void levelOrder(Node* root) {
    if (root== NULL) {
		cout << "Empty tree \n"; 
		return; 
	}
    
	queue<Node*> q;
    q.push(root);
    
	int level = 1;
    while (!q.empty()) {
        int levelSize = q.size();
        cout << "Level:"<<level<<": ";
        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front(); q.pop();
            cout << curr->val << " ";
            if (curr->left)  q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << "\n";
        level++;
    }
}

 
int main() {
    Node* root = Build();
    cout << "\nLevel Order Traversal:\n";
    levelOrder(root);
    return 0;
}

