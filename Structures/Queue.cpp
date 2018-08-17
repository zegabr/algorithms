#include <iostream>
using namespace std;
struct no{
    int info;
    no *prox;
};
struct fila{
    no *inicio,*fim;

};

fila *inserir(fila *q,int info){
        no *aux = new no();
        aux->info=info;
        aux->prox=NULL;
    if(q->inicio==NULL){
        q->inicio=q->fim=aux;
        return q;
    }else{
        q->fim->prox=aux;
        q->fim=aux;
        return q;
    }
}

fila *remover(fila *q){
    if(q->inicio!=NULL)
        q->inicio=q->inicio->prox;
    else
        cout<<"cannot remove because it is empty, you can cry now\n";

    if(q->inicio==NULL)//if its empty
        q->fim=NULL;
    return q;
}

void imprime(fila *q){
    no *aux = q->inicio;
    cout<<"inicio<---->fim\n";
    while(aux!=NULL){
        cout<<aux->info<<" ";
        aux=aux->prox;
    }
    cout<<endl;
}
bool seminicio(fila *q){
    return q->inicio==NULL ? true : false;
}
int quantotemnainicio(fila *q){
    return q->inicio->info;
}
int quantotemnafim(fila *q){
    return q->fim->info;
}

int main(){
    fila *q= new fila();
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
