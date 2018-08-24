//resolução da questão "precisa-se de matematicos em marte"(URI judge)
//conceito Binary Indexed Tree

#include<iostream>
using namespace std;


int n,ind,inCar[100005],bit[100005];
char c;

int sum(int i){
    int res =0;
    while (i){
        res += bit[i];
        i-= i&-i;
    }
    return res;
}
void ad(int i,int val){
    while(i<n){
        bit[i]+=val;
        i+= i&-i;
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>inCar[i];
        ad(i,inCar[i]);   
        //cout<<bit[i]<<' ';
    }
    //cout<<endl;

    while(cin>>c){
        cin>>ind;
        if(c=='?'){//pega soma de 1 a ind-1
            cout<< sum(ind-1) <<endl;  
        }else{//abduz ind
            ad(ind,-inCar[ind]);
        }
    }

}