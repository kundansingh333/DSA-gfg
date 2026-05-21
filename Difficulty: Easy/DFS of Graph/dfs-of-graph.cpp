class Solution {
  public:
    vector<int>ans;
    void n_dfs(vector<vector<int>>&adj,int node,vector<bool>&visited){
        ans.push_back(node);
        visited[node]=1;
        for(auto nbr:adj[node]){
            if(!visited[nbr]){
                n_dfs(adj,nbr,visited);
            }
        }
        
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<bool>visited(n,0);
        n_dfs(adj,0,visited);
        return ans;
    }
};