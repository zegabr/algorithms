#include<iostream>
using namespace std;
#define null NULL


template<class T>
class node{
	public:
		T info;
		node *left, *right;
		node(T val){
			info = val;
			left=right=null;
		}
};

template<class T>
class bst{
	private:
		node<T> *root;

	public:
		bst(){root=null;}
		bool empty(){
			return root==null;
		}
		void insert(T val, node<T> *R = root){
			if(empty()){
				node<T> *n = new node<T>(val);
				root = n;
			}else if(val < R->info) insert(val, R->left);
			else if(val > R->info) insert(val, R->left);
		}

		void preorder(node<T> *R = root){
			if(root==null) return;
			if(root->left!=null) preorder(R->left);
			cout<<R->info<<' ';
			if(root->right!=null) preorder(R->right);

		}

};


int main(){
	bst<int> s;


}
