class Solution {
  public:
    deque<int>dq;
    void dfs(int src,vector<int>&visited,vector<vector<int>>&adj){
        visited[src]=1;
        for(auto &x:adj[src]){
            if(!visited[x]){
                dfs(x,visited,adj);
            }
        }
        dq.push_front(src);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto &x:edges){
            int a=x[0];
            int b=x[1];
            adj[a].push_back(b);
        }
        
        vector<int>visited(V,0);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(i,visited,adj);
            }
        }
        vector<int>ans;
        
        for(auto &x:dq){
            ans.push_back(x);
        }
        return ans;
        
    }
};