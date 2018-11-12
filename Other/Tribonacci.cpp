//solution for https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3914
#include <bits/stdc++.h>
using namespace std;
char pl = '\n',sp=' ';
typedef long long ll;
typedef pair<int,int> pii;
const ll mod = 1e9+9;
ll T[3][3]={ {0, 1, 0},
			{0, 0, 1},
			{1, 1, 1}};
ll ansT[3][3]={
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};
ll ansT2[3][3],T2[3][3];//auxiliars
ll base[3] = {2,1,0}, ans; 

void cpy(ll a[][3], ll b[][3]){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			a[i][j] = b[i][j];

}
void reset(){
	ansT[0][0]=1;
	ansT[0][1]=0;
	ansT[0][2]=0;
	ansT[1][0]=0;
	ansT[1][1]=1;
	ansT[1][2]=0;
	ansT[2][0]=0;
	ansT[2][1]=0;
	ansT[2][2]=1;
	
	T[0][0]=1;
	T[0][1]=1;
	T[0][2]=1;
	T[1][0]=1;
	T[1][1]=0;
	T[1][2]=0;
	T[2][0]=0;
	T[2][1]=1;
	T[2][2]=0;
	 
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	ll n,i,j,val,k;
	while(cin>>n and n){
		//at the end we have ansT*base = ans
		//answer at ans[0]
		reset();
		n--;
		while(n){//fast exp of T
			if(n&1){
			//ansT=ansT*T %mod
				for(i=0;i<3;i++){
					for(j=0;j<3;j++){
						ansT2[i][j]=0;
						for(k=0;k<3;k++){
							ansT2[i][j]+=(ansT[i][k]*T[k][j])%mod;
							ansT2[i][j]=ansT2[i][j]%mod;
						}
					}
				}
				cpy(ansT,ansT2);
			
			}
			n>>=1;
			//T=T*T % mod
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					T2[i][j]=0;
					for(k=0;k<3;k++){
						T2[i][j]+=(T[i][k]*T[k][j])%mod;
						T2[i][j]=T2[i][j]%mod;
					}
				}
			}
			cpy(T,T2);
			
					
			
			 
			
		}
		//now do ansT*base = ans and get ans[0]
		//because ansT must be equal T^(n-1) by fast expo above
		ans=0;
		for(i=0;i<3;i++)
			ans=(ans+ (ansT[2][i]*base[i])%mod)%mod;
		
	
	cout<<ans<<pl;
	}
}

