void toposort(int start){
    visited[start]=true;
        for(int i=0;i<adj[start].size();i++){
            int child = adj[start][i];
            if(!visited[child]){
                toposort(child);
            }
        }

        toposorted.push_back(start);
}
