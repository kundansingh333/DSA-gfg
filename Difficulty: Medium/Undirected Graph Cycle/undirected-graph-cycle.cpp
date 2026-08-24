class Solution {
  public:
    bool dfs(vector<vector<int>>&adj,vector<bool>&visited,int parent,int src){
        visited[src]=true;
        for(auto &nbr:adj[src]){
            if(!visited[nbr]){
                bool ans=dfs(adj,visited,src,nbr);
                if(ans) return true;
            }else if(visited[nbr]==true && parent!=nbr){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i=0; i<edges.size(); i++){
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool>visited(V,false);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                bool ans=dfs(adj,visited,-1,i);
                if(ans) return true;
            }
        }
        return false;
        
    }
};