#include<iostream>
using namespace std;



class Node{
	public:
		int val;
		Node *left, *right;
		Node(int val){
			this->val = val;
			left = right = NULL;
		}
};


class BST{
	private:
		Node *root;
		void inorder(Node *R){
			if(R == NULL) return;
			inorder(R->left);
			cout << R->val << ' ';
			inorder(R->right);
		};
		Node* insert(Node * node, int val){
			if(node == NULL){
				return new Node(val);
			}
			if(val < node->val){
				if(node->left == NULL){
					node->left = new Node(val);
					return node;
				}else node->left = insert(node->left, val);
			}else if(val > node->val){
				if(node->right == NULL){
					node->right = new Node(val);
					return node;
				}else node->right = insert(node->right, val);
			}
			return node;
		}

		Node* remove(Node *node, int val){
			if(node == NULL) return NULL;
            if(val < node->val) node->left = remove(node->left, val);
            else if(val > node->val) node->right = remove(node->right, val);
            else{
                if(!node->left) return node->right;
                if(!node->right) return node->left;
                
                Node* curr = node->right;
                while(curr->left and curr->left->left)
                    curr = curr->left;
                
                if(curr->left){
                    node->val = curr->left->val;
                    curr->left = curr->left->right;
                }else{
                    node->val = curr->val;
                    node->right = curr->right;
                }
            }
            return node;
		}

	public:
		BST(): root(NULL){}
		bool empty(){
			return root == NULL;
		}
		void insert(int data){ root = insert(root, data);} 
		void inorder(){ inorder(root);}
		void remove(int data) {root = remove(root, data);}
};

int main(){
	BST s;

	s.insert(10);
	s.insert(11);
	s.insert(5);
	s.insert(20);
	s.insert(1);
	s.inorder(); cout << endl;
	s.remove(5);
	s.remove(20);
	s.remove(11);
	s.remove(10);
	s.inorder(); cout << endl;
	s.remove(1);
	s.remove(5);
	s.inorder(); cout << endl;
	


}
