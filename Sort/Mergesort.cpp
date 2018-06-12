#include <bits/stdc++.h>
using namespace std;
void p(int *a,int l,int r){
    for(int i=l;i<=r;i++){
        cout<<a[i]<<" ";
    }
    
}
void merge(int a[],int b[],int l, int mid,int r){
    int i,j,k;
    cout<<"\nmerging:( "; p(a,l,mid); cout<<") and ("; p(a,mid+1,r); cout<<")\n";
    i=k=l;//primeiro indice da esquerda (0 no exemplo abaixo)
    j = mid+1;//primeiro indice do array da direita (4 no exemplo abaixo)
    while(i<=mid && j<=r){//i=0,1,2,...,mid  j = mid+1,mid+2...r
        if(a[i]<=a[j]){
            b[k]=a[i]; 
            i++;
            k++;
        }else{
            b[k]=a[j]; 
            j++;
            k++;
        }
    }
    while(i<=mid){//pega oq nao foi pego da esquerda
        b[k]=a[i]; 
        i++;
        k++;
    }
    while(j<=r){//pega oq nao foi pego da direita
        b[k]=a[j]; 
        j++;
        k++;
    }
    for(i=l;i<=r;i++)
        a[i]=b[i];
    cout<<"merged to: (";p(b,l,r);cout<<")\n";
}
void mergesort(int a[],int b[],int l,int r){//ex.. l=0,r=6 (7elementos)
    if(r<=l)
        return ;
        
    int mid = (r+l)/2;//mid=int 3,5 = 3
    mergesort(a,b,l,mid);//chama merge de 0 a 3
    mergesort(a,b,mid+1,r);//chama merge de 4 a 6
    merge(a,b,l,mid,r);
    
}

int main(){
    int a[]={47,26,33,5,99,38,64,15};
    int n = sizeof(a)/sizeof(int);
    int b[n];
    p(a,0,n-1);cout<<endl;
    mergesort(a,b,0,n-1);
    cout<<"a: ";p(a,0,n-1);cout<<endl;
    cout<<"b: ";p(b,0,n-1);cout<<endl;
    
    return 0;
}