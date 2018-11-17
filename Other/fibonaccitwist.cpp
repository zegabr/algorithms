//matrix fast exponentiation for fibonnacci with a twist question
#include <bits/stdc++.h>
using namespace std;
char pl = '\n',sp=' ';
typedef long long ll;
#define tam 4
ll aux[tam][tam];//auxiliares
ll base[tam] = {1,0,1,1}, ans,mod; 
ll n,i,j,val,k,t;

void cpy(ll a[][tam], ll b[][tam]){//a <=== b
	for(int i=0;i<tam;i++)
		for(int j=0;j<tam;j++)
			a[i][j] = b[i][j];
}

void mult(ll a[][tam], ll b[][tam]){//a <=== a*b
				for(i=0;i<tam;i++){
					for(j=0;j<tam;j++){
						aux[i][j]=0;
						for(k=0;k<tam;k++){
							aux[i][j]+=(a[i][k]*b[k][j])%mod;
						}
					}
				}
		cpy(a,aux);
}
void fexpT(ll T[][tam],ll ansT[][tam], ll k){//ansT = T^k-1
		k--;
		while(k){//fast exp of T
			if(k&1){
				mult(ansT,T); //ansT=ansT*T %mod
			}
			k>>=1;
			mult(T,T);//T=T*T % mod
		}
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>mod;
		if(n<2){
			cout<<n<<pl;
			continue;
		}
		//at the end we have ansT*base = ans
		//answer at ans[0]
		ll T[tam][tam]={ 
		{1, 1, 1, 0},
		{1, 0, 0, 0},
		{0, 0, 1, 1},
		{0, 0, 0, 1}};
		ll ansT[tam][tam]={//exponenciacao de T eh salva aqui
		{1,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{0,0,0,1}
	};
		fexpT(T,ansT, n);
		//now do ansT*base = ans and get ans[0]
		//becaus ansT must be equal T^n by fast expo above
		ans=0;
		for(i=0;i<tam;i++)
			ans=(ans+ (ansT[0][i]*base[i])%mod)%mod;

	cout<<ans<<pl;
	}
}
