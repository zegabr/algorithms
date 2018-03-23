#include <bits/stdc++.h>
using namespace std;
struct node{
    int key;
    node *next;
};
struct filha{
    node *cabeca,*bunda;

};
filha *inserir(filha *q,int key){
        node *aux = new node();
        aux->key=key;
        aux->next=NULL;
    if(q->cabeca==NULL){
        q->cabeca=q->bunda=aux;
        return q;
    }else{
        q->bunda->next=aux;
        q->bunda=aux;
        return q;
    }
}
filha *remover(filha *q){
    if(q->cabeca!=NULL)
        q->cabeca=q->cabeca->next;
    else
        cout<<"cannot remove because it is empty, you can cry now\n";
    return q;
}
void imprime(filha *q){
    node *aux = q->cabeca;
    while(aux!=NULL){
        cout<<aux->key<<" ";
        aux=aux->next;
    }
    cout<<endl;
}

int main(){
    filha *q= new filha();
    //inserting
    q = inserir(q,1);
    imprime(q);
    q = inserir(q,2);
    imprime(q);
    q = inserir(q,3);
    imprime(q);
    q = inserir(q,4);
    imprime(q);
    //removing
    q = remover(q);
    imprime(q);
    q = remover(q);
    imprime(q);
    q = remover(q);
    imprime(q);
    q = remover(q);
    imprime(q);
    //trying to remove nothing
    q = remover(q);
    imprime(q);


    return 0;
}
