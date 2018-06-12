#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
priority_queue <ii,vii,greater<ii>> tovisit;
typedef vector<int> vi;

int minD[20000];
vii adj[20000];
int t,v,e,S,T,a,b,w,infi;

bool dijkstra(int S, int T){
    bool way =false;
    int edgeweight,current,child,weightTillNow;
    ii aux;
    tovisit.push(make_pair(minD[S],S));

    while(!tovisit.empty()){
        aux=tovisit.top(); tovisit.pop();
        current=aux.second;

            for(int i=0;i<adj[current].size();i++){
                aux=adj[current][i];
                edgeweight=aux.first;
                child=aux.second;
                if(child==T)
                    way=true;

                if(minD[current]+edgeweight<minD[child]){
                    
                    minD[child]=minD[current]+edgeweight;
                    tovisit.push(make_pair(minD[child],child));
                }
            }


         
        

    }

    return way;
}

int main(){
    scanf("%d ",&t);
    for(int i=1;i<=t;i++){
        scanf("%d %d %d %d",&v,&e,&S,&T);//v vertices, e arestas, S e T posicoes inicial e final
        infi=0;
        
        for(int j=0;j<v;j++)
            adj[j].clear();
        
        while(e--){
            scanf("%d %d %d",&a,&b,&w);
            infi+=w;
            adj[a].push_back(make_pair(w,b));
            adj[b].push_back(make_pair(w,a));
        }

        while(!tovisit.empty())
            tovisit.pop();
        
        for(int k=0;k<v;k++){//equivalent to memset??
             minD[k]=infi+1;
             //printf(" dto%d = %d",k,minD[k]);
        }
        
        minD[S]=0;
         
        
        if(dijkstra(S,T))
            printf("Case #%d: %d\n",i,minD[T]);
        else
            printf("Case #%d: unreachable\n",i);
        
    }


    return 0;
}



