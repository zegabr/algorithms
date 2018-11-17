#include <iostream>
using namespace std;
char pl = '\n',sp=' ';
typedef long long ll;
#define tam 5
const ll mod=1e9+7;
void cpy(ll a[][tam], ll b[][tam]){
	for(int i=0;i<tam;i++)
		for(int j=0;j<tam;j++)
			a[i][j]=b[i][j];
}
void mult(ll a[][tam], ll b[][tam]){
	int i,j,k;
	ll aux[tam][tam];
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			aux[i][j]=0;
			for(k=0;k<tam;k++){
				aux[i][j]+=(a[i][k]*b[k][j])%mod;
				aux[i][j]=aux[i][j]%mod;
			}	
		}
	}cpy(a,aux);

}
void fexpT(ll T[][tam], ll ansT[][tam], ll k){
	k-=3;
	while(k){
		if(k&1) mult(ansT,T);
		k>>=1; mult(T,T);
	}
}
ll tetra(ll n){
	if(n<3)return 0;
	if(n==3)return 1;
	ll T[tam][tam]={{1,1,1,1,0},{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{1,1,1,1,1}},
	ansT[tam][tam]={{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1}},
	base[tam] = {1,0,0,0,1};;
	fexpT(T,ansT,n);
	ll ans=0;
	for(int i=0;i<tam;i++) ans=(ans + (ansT[4][i]*base[i])%mod)%mod;


return ans;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	int t,i;
	ll a,b,ans;
	cin>>t;
	while(t--){
		cin>>a>>b;
		ans=(tetra(b)-tetra(a-1))%mod;
		if(ans<0)ans+=mod;
        cout<<ans<<pl;
		
		}
	
	
	
	
	}
