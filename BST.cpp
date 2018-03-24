#include <iostream>
using namespace std;

struct node{
    int key;
    struct node *left,*right;
}typedef Node;

Node * insert(Node *root, int key){
    if(root==NULL){
        root = new Node;
        root->key=key;
        root->left=root->right=NULL;
    }else if(key<root->key){
        root->left = insert(root->left,key);
    }else if(key>root->key){
        root->right = insert(root->right,key);
    }
        return root;
}
void posOrder(Node *raiz) {
	if(raiz != NULL) {
		posOrder(raiz->left);
		posOrder(raiz->right);
		cout << raiz->key << endl;
	}
}

int main(){
    int key;
    Node *tree=NULL;
    while(cin >> key){
	
        tree=insert(tree,key);
	
    }
    posOrder(tree);

    return 0;
}
