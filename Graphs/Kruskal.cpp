
          

Begin: 2018-06-12 19:03 UTC-3
 Lista 3 - MST e DSU
End: 2018-06-19 01:03 UTC-3
150:00:00
Ended
Overview
Problem
Status
Rank (150:00:00)
0 Comments
Previous12345…Next
Username

Prob
	Result 
	Time
(ms)	Mem
(MB)	Lang 
	Submit Time
jgsp2
A
Accepted
510		
C++
11 days ago
           
All Copyright Reserved ©2018 Xu Han
Server Time: 2018-06-25 08:59:42 UTC-3

#14275276 | jgsp2's solution for [UVA-11631] [Problem A]
Status
Accepted
Time
510ms
Length
854
Lang
C++11 5.3.0
Submitted
2018-06-14 15:39:21
Shared

RemoteRunId
21474556
Select Code
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
int find(int i){
	if(ds[i]==i)
		return i;
	return ds[i]=find(ds[i]);
}
bool uni(int a, int b){
	
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
		for(int i=0;i<e;i++){
			ed=edges[i];
			a=ed.second.first; b=ed.second.second;
			if(uni(a,b)){
				
				mst+=ed.first;
			}
		
		}
		
		cout<<total-mst<<endl;
	
	
	}

    return 0;
}
   
        

