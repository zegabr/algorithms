

bool DFS(vector<int> adj[],int V,int start,int goal){//iterative dfs
    stack<int> tovisit;
    bool explored[V];
    int node;
    
    for(int i=0;i<V;i++){
        explored[i]=false;
    }
    
    tovisit.push(start);
    explored[start]=true;
    

    while(!tovisit.empty()){
        int current = tovisit.top();
        tovisit.pop();

        for(auto node: adj[current]){
            if(explored[node]==false){//if adjacent node has not been explored
                tovisit.push(node);
                if(node==goal)//if there is a way
                    return true;//return that you know the way
                    
            }
        }
        explored[current]=true;
    }
    
  return false;  
}

