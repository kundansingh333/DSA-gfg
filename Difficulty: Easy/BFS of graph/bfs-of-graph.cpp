class Solution {
  public:
    void fun(vector<vector<int>>&adj,vector<bool>&visited,int src,vector<int>&ans){
        queue<int>q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            ans.push_back(f);
            for(auto &nbr:adj[f]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
        
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        vector<bool>visited(n,false);
        vector<int>ans;
        fun(adj,visited,0,ans);
        return ans;
    }
};