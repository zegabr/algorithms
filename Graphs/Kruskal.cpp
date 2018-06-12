#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vector <iii> edgesList;
int color[200000], vertices,edges,a,b,w,wmax,wmin,nextcolor,colorbefore,mergecolor;
ii ab;
iii w_ab;


int main(){
    while(cin>>vertices>>edges && vertices!=0){
        
        edgesList.clear(); 

        wmax=0;
        for(int i=0;i<edges;i++){
            color[i]=-1;//clear reset color
           
            cin>>a>>b>>w;
            wmax+=w;
            ab=make_pair(a,b);
            w_ab=make_pair(w,ab);//triple created
            edgesList.push_back(w_ab);//adding triple to edgelist
        }
        sort(edgesList.begin(),edgesList.end());//in crescent order of weights
        
        wmin=0;//Kruskal MST total weight
        nextcolor=0;
        for(int i=0;i<edges;i++){
            w_ab=edgesList[i];
            w=w_ab.first;
            ab=w_ab.second;
            a=ab.first; b=ab.second;
            
            
            if(color[a]==-1 && color[b]==-1){//if neither one of vertices are in MST
                color[a]=color[b]=++nextcolor;
                wmin+=w;
            }else if(color[a]==-1){//if b is but a isnt
                color[a]=color[b];
                wmin+=w;
            }else if(color[b]==-1){//if a is but b isnt
                color[b]=color[a];
                wmin+=w;
            }else{//both are in MST
                if(color[a]!=color[b]){
                    colorbefore=color[a];
                    mergecolor=color[b];
                    for(int k=0;k<edges;k++){
                        if(color[k]==colorbefore)
                            color[k]=mergecolor;
                    }
                    wmin+=w;
                }
            }
            

        }
        
        
        cout<<wmax-wmin<<endl;
    }





    return 0;
}
