#include <bits/stdc++.h>
using namespace std;

struct heap{
    int arr[100];
    int n=0;//will be the current element quantity
    heap(){

    }
    
}typedef Heap;

void swap(int *a,int *b){
    int aux = *a;*a=*b;*b=aux;
}

int leftkid(int n,int parent){
    int left = parent*2+1;
    if(left<=n)
        return left;
    else
        return -1;
    }
int rightkid(int n,int parent){
    int right = parent*2+2;
    if(left<=n)
        return left;
    else
        return -1;
    
}


int main(){
    Heap *H = new Heap();
    
    


return 0;
}