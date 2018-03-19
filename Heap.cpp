#include <bits/stdc++.h>
using namespace std;

struct Heap{
    int arr[1000000];
    int n;//will be the current element quantity
    
    
}typedef Heap;

void swap(int *a,int *b){
    int aux = *a;*a=*b;*b=aux;
}

int leftkid(Heap *H,int parent){
    int left = (parent*2+1);
    if(left<=H->n)
        return left;
    else
        return -1;
    }
int rightkid(Heap *H,int parent){
    int right = (parent*2+2);
    if(right<=H->n)
        return right;
    else
        return -1;
    
}
void siftUp(Heap *H, int index){

}
void siftDown(Heap *H, int index){

}
void insert(Heap *H, int key){
    if(H->n+1<1000000){
        H->arr[H->n]=key;
        H->n++;
        siftUp(H, H->n-1);
    }
}
int remove(Heap *H){
    int key = H->arr[0];
    H->arr[0] = H->arr[H->n];
    H->n--;
    siftDown(H,0);
    return key;
}
void heapfy(Heap *H){

}
void heapsort(Heap *H){

}
void print(Heap *H){
    for(int i= 0;i<=H->n;i++)
        cout<<H->arr[i]<<" ";

    cout<<endl;
}

int main(){
    Heap *H = new Heap();
    
    


return 0;
}