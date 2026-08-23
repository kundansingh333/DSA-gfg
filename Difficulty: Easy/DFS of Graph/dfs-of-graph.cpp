class Solution {
  public:
    
    void fun(vector<vector<int>>&adj,vector<bool>&visited,int root,vector<int>&ans){
        ans.push_back(root);
        visited[root]=true;
        for(auto &nbr:adj[root]){
            if(!visited[nbr]){
                fun(adj,visited,nbr,ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int>ans;
        vector<bool>visited(n,false);
        fun(adj,visited,0,ans);
        return ans;
    }
};