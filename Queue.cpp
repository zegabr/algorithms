#include <iostream>
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

    if(q->cabeca==NULL)//if its empty
        q->bunda=NULL;
    return q;
}

void imprime(filha *q){
    node *aux = q->cabeca;
    cout<<"cabeca<---->bunda\n";
    while(aux!=NULL){
        cout<<aux->key<<" ";
        aux=aux->next;
    }
    cout<<endl;
}
bool semCabeca(filha *q){
    return q->cabeca==NULL ? true : false;
}
int quantotemnacabeca(filha *q){
    return q->cabeca->key;
}
int quantotemnabunda(filha *q){
    return q->bunda->key;
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
