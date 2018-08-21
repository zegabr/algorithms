#include <iostream>
using namespace std;
struct node{
    int key;
    node *next;
};
struct Stck{
    node *topper;
};
Stck *insert(Stck *s,int key){
    node *aux = new node();
    aux->key=key;
    aux->next=NULL;
    if(s->topper==NULL){//stack is empty
        s->topper=aux;
    }else{//not empty
        aux->next=s->topper;
        s->topper=aux;
    }
        return s;
}
Stck *remove(Stck *s){
    if(s->topper==NULL){
        cout<<"stack is empty, cannot remove element\n";
        return s;
    }
    else{
        s->topper=s->topper->next;
        return s;
    }
}
bool isEmpty(Stck *s){
    return s->topper == NULL ? true : false;
}
void printS(Stck *s){
    node *aux = s->topper;
    cout<<"top<---\n";
    while(aux!=NULL){
        cout<<aux->key<<" ";
        aux=aux->next;
    }
    cout<<endl;
}

int main(){
    Stck *s = new Stck();

    s=remove(s);
    
    s=insert(s,5);
    printS(s);
    s=insert(s,3);
    printS(s);
    s=insert(s,19);
    printS(s);
    s=insert(s,8);
    printS(s);

    s=remove(s);
    s=remove(s);
    printS(s);

    return 0;
}