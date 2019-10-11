#include<iostream>
using namespace std;
#define null NULL



class node{
	public:
		int info;
		node *left, *right;
		node(int val){
			info = val;
			left=right=null;
		}
};


class bst{
	private:
		node *root;
		void inorder(node *R);
		void insert(int val, node * R);
	public:
		bst(){root=null;}
		bool empty(){
			return root==null;
		}
		void insert(int data){ insert(data, root);} 
		void inorder(){ inorder(root);};



};
void bst::insert(int val, node * R){
	if(root==null){
		node *aux = new node(val);
		root = aux;
		return;
	}
	if( val < R->info){
		if(R->left==null){
			node *aux = new node(val);
			R->left = aux;
			return;
		}else insert(val, R->left);
	}else if( val > R->info){
		if(R->right==null){
			node *aux = new node(val);
			R->right = aux;
			return;
		}else insert(val, R->right);
	}
}
void bst::inorder(node *R){
	if(R==null) return;
	if(R->left) inorder(R->left);
	cout<<R->info<<' ';
	if(R->right) inorder(R->right);
}

int main(){
	bst s;

	s.insert(10);
	s.insert(11);
	s.insert(5);
	s.insert(20);
	s.insert(1);
	s.inorder();
	


}
