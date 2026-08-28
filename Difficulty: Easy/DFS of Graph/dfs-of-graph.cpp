class Solution {
  public:
    
    void dfs_traversal(vector<vector<int>>&adj,int src,vector<int>&visited,vector<int>&ans){
        visited[src]=1;
        ans.push_back(src);
        for(auto &nbr:adj[src]){
            if(!visited[nbr]){
                dfs_traversal(adj,nbr,visited,ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>&adj){
        int n=adj.size();
        vector<int>ans;
        vector<int>visited(n,0);
        dfs_traversal(adj,0,visited,ans);
        return ans;
    }
};