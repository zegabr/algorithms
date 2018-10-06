
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;


vector <iii> edges;
int v,e,a,b,w,total,mst;
int ds[200000+10];
iii ed;

void makeset(){
	for(int i=0;i<v;i++)
		ds[i]=i;
}
int find(int i){//find
	if(ds[i]==i)
		return i;
	return ds[i]=find(ds[i]);
}
bool uni(int a, int b){//union
	
	if(find(a)==find(b))
		return false;
	else{
		ds[find(b)]=find(a); 
		return true;
	}
}


int main(){
    //ios::sync_with_stdio(0); cin.tie(0);
	
	while(cin>>v>>e && v!=0){
		total=mst=0;
		edges.clear();
		for(int i=0;i<e;i++){
			cin>>a>>b>>w;
			edges.push_back({w,{a,b}});
			total+=w;
		}
		sort(edges.begin(),edges.end());
		makeset();
		for(auto ed : edges){
			a=ed.second.first; b=ed.second.second;
			if(uni(a,b)){
				mst+=ed.first;
			}
		
		}
		
		cout<<total-mst<<endl;
	
	
	}

    return 0;
}
   
        

