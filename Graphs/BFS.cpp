//BFS FOR UNWEIGHTED GRAPHS MINIMUM DISTANCE

int BFS(vector<int> adj[],int V,int start,int goal){
    queue<int> tovisit;
    bool explored[V];
    int pathcounter[V],node;
    for(int i=0;i<V;i++){
        explored[i]=false;
        pathcounter[i]=V;
    }
    
    tovisit.push(start);
    explored[start]=true;
    pathcounter[start]=0;

    while(!tovisit.empty()){
        int current = tovisit.front();
        tovisit.pop();

        for(auto node : adj[current]){
            if(explored[node]==false){//if adjacent node has not been explored
                tovisit.push(node);
                if(pathcounter[current]+1<pathcounter[node])
                    pathcounter[node]=pathcounter[current]+1;
            }
        }
        explored[current]=true;
    }
    //for(int i=0;i<V;i++)
      //  cout<<"least bridges to "<<i<<" is "<<pathcounter[i]<<endl;
  return pathcounter[goal]==V ? -1 : pathcounter[goal];  
}
