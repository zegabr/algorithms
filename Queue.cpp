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
    q->cabeca=q->cabeca->next;
    return q;
}
void imprime(filha *q){
    node *aux = q->cabeca;
    while(aux!=NULL){
        cout<<aux->key<<endl;
        aux=aux->next;
    }
}

int main(){
    filha *q= new filha();
    q = inserir(q,1);
    q = inserir(q,2);
    q = inserir(q,3);
    q = inserir(q,4);
    q = remover(q);
    imprime(q);


    return 0;
}