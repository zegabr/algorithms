#include <bits/stdc++.h>
using namespace std;

struct Heap{
    int arr[1000000];
    int n;//will be the current element quantity
}typedef Heap;

void swap(Heap *H,int a,int b){
    int aux = H->arr[a];H->arr[a]=H->arr[b];H->arr[b]=aux;
}
void heapfy(Heap *h,int i,int n);

void buildHeap(Heap *H){
	for(int i=(H->n)/2;i>=0;i--){
        int n = H->n;
		heapfy(H,i, n);
		}
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
void siftUp(Heap *h, int i){
	int trocou=1,parent;
    while(i>0&&trocou){
    	trocou=0;
		parent = (i-1)/2;
		if(h->arr[i] > h->arr[parent]){
			swap (h, i, parent);
			i=parent;
			trocou=1;
	    }
}
}
void heapfy(Heap *h,int i,int n){
    //siftDown?? yes it is
	int trocou=1,left,right;
    while (i<n/2 && trocou){
    	trocou = 0;
        left=leftkid(h,i);
        right=rightkid(h,i);
        if(right >=0){//means it has right child
        	int bigger= h->arr[left] > h->arr[right] ? left : right;
            if(h->arr[i] < h->arr[bigger]){
                swap(h, i, bigger);
                i=bigger;
                trocou=1;
             }
        }else{//in case it has only left child
        	if(h->arr[i] < h->arr[left]){
        	    swap(h, i, left);
                i=left;
                trocou=1;
            }
        }
    } 
	
	}
void insert(Heap *H, int key){
    if(H->n+1<1000000){
        H->arr[H->n]=key;
        H->n++;
        siftUp(H, H->n-1);
    }else
        cout<<"full heap, cannot insert\n";
}
int remove(Heap *h){
	if(h->n > -1){//if its not empty
        int key=h->arr[0];
		h->arr[0]=h->arr[h->n-1];
		h->n--;
        int n=h->n;
		heapfy(h, 0,n);//siftdown
        return key;
	}else
	  cout<<" empty heap, cannot remove\n ";
	return -1;
}

void print(Heap *H){
    for(int i= 0;i<=H->n-1;i++)
        cout<<H->arr[i]<<" ";

    cout<<endl;
}
void heapsort(Heap *h){
	if(h->n>0){//if is -1 it is empty, if is 0, it has only one element
        for(int i=h->n-1;i>0;i--){
		    swap (h, 0, i); //swap bigger one with last one
		    heapfy(h,0, i-1);//heapfy until i-1 position
		
		}
	}
	
	
}


int main(){
    Heap *H = new Heap();
    
    insert(H,2);
    insert(H,7);
    insert(H,26);
    insert(H,25);
    insert(H,19);
    insert(H,17);
    insert(H,1);
    insert(H,90);
    insert(H,3);
    insert(H,36);
    heapsort(H);
    print(H);


    return 0;
}