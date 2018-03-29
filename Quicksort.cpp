#include <bits/stdc++.h>
using namespace std;
void p(int *a,int l,int r){
    for(int i=l;i<=r;i++){
        cout<<a[i]<<" ";
    }
    
}
void kawarimi(int *a,int *b){
    int aux=*a;*a=*b;*b=aux;
}
int partition(int *a,int l,int r){//quicksort
    p(a,l,r);cout<<endl;
    int pivot = a[l]; cout<<"pivot="<<pivot<<endl;
    int i= l,j=r;
    while(i<j){
        while(a[i]<=pivot)
            i++;
        while(a[j]>pivot)
            j--;
        if(i<j){
            kawarimi(&a[i],&a[j]);
            cout<<a[i]<<" and "<<a[j]<<" swaped\n";
        }
    }
    kawarimi(&a[l],&a[j]);
    cout<<"pivot ("<<pivot<<") and "<<a[l]<<" swaped (pivot now placed correctly)\n";
    p(a,l,r);cout<<endl<<endl;
    return j;
}
void quicksort(int *a,int l,int r){
    if(l>=r)
        return;

    int p = partition(a,l,r);
    quicksort(a,l,p);
    quicksort(a,p+1,r);
}


int main(){
    int a[]={100,47,26,33,5,99,38,64,15,7,988,543};
    int n = sizeof(a)/sizeof(int);
    int b[n];
    //p(a,0,n-1);cout<<endl;
    //mergesort(a,b,0,n-1);
    
    quicksort(a,0,n-1);
    p(a,0,n-1);cout<<endl;
    
    
    return 0;
}