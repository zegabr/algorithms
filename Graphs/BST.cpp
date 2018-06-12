#include <iostream>
using namespace std;

struct node{
    int key;
    struct node *left,*right;
};

node *insert(node *root, int key){
    if(root==NULL){
        root = new node;
        root->key=key;
        root->left=root->right=NULL;
    }else if(key<root->key){
        root->left = insert(root->left,key);
    }else if(key>root->key){
        root->right = insert(root->right,key);
    }
        return root;
}
void inorder(node *raiz) {
	if(raiz != NULL) {
		inorder(raiz->left);
		cout << raiz->key << " ";
		inorder(raiz->right);
	}
}
node *del(node *root,int key){
    if(root==NULL)
        return root;
    else{
        if(key<root->key)
            root->left = del(root->left,key);
        else if(key>root->key)
            root->right = del(root->right,key);
        else{//key == root->key
            if(root->right==NULL && root->left==NULL)//no child
                return NULL;
            else{//one or two child
                if(root->left==NULL)//only right child
                    return root->right;
                else if(root->right==NULL)
                    return root->left;
                else{//has two childs
                    node * aux = root->right;
                    while(aux->left!=NULL)
                        aux=aux->left;
                    //now aux is inorder successor
                    root->key=aux->key;
                    root->right = del(root->right,root->key);
                }
            }

        }


    }
    return root;
}
int main(){
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    cout<<"Inorder traversal of the given tree \n";
    inorder(root);
 
    cout<<"\nDelete 20\n";
    root = del(root, 20);
    cout<<"Inorder traversal of the modified tree \n";
    inorder(root);
 
    cout<<"\nDelete 30\n";
    root = del(root, 30);
    cout<<"Inorder traversal of the modified tree \n";
    inorder(root);
 
    cout<<"\nDelete 50\n";
    root = del(root, 50);
    cout<<"Inorder traversal of the modified tree \n";
    inorder(root);
 
    return 0;
}
