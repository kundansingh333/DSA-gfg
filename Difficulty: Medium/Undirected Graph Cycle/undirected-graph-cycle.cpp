class Solution {
  public:
    int dfs(vector<vector<int>>&adj,vector<int>&visited,int &parent,int src){
        visited[src]=1;
        for(auto &nbr:adj[src]){
            if(!visited[nbr]){
                int ans=dfs(adj,visited,src,nbr);
                if(ans) return 1;
            }else if(visited[nbr] && parent!=nbr){
                return 1;
            }
        }
        visited[src]=0;
        return 0;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(auto &edge:edges){
            int a=edge[0];
            int b=edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        vector<int>visited(V,0);
        int parent=-1;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                int ans=dfs(adj,visited,parent,i);
                if(ans) return true;
            }
        }
        return false;
        
        
        
    }
};