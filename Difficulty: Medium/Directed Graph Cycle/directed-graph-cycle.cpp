class Solution {
  public:
  
    bool fun(int src, vector<vector<int>>&adj, vector<bool>&visited, vector<int>&current_path){
        visited[src]=true;
        current_path[src]=1;
        for(auto &nbr:adj[src]){
            if(!visited[nbr]){
                bool ans=fun(nbr,adj,visited,current_path);
                if(ans) return true;
            }else{
                if(current_path[nbr]==1){
                    return true;
                }
            }
        }
        current_path[src]=0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto edge:edges){
            int a=edge[0];
            int b=edge[1];
            adj[a].push_back(b);
        }
        vector<bool>visited(V,false);
        vector<int>current_path(V,0);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                bool ans=fun(i,adj,visited,current_path);
                if(ans) return true;
            }
        }
        return false;
    }
};