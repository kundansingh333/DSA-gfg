class Solution {
  public:
    void fun(vector<vector<int>>&adj,vector<int>&visited,vector<int>&ans,int src){
        queue<int>q;
        visited[src]=1;
        q.push(src);
        while(!q.empty()){
            int f=q.front();
            q.pop();
            ans.push_back(f);
            for(auto &nbr:adj[f]){
                if(!visited[nbr]){
                    visited[nbr]=1;
                    q.push(nbr);
                }
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        vector<int>visited(n,0);
        vector<int>ans;
        fun(adj,visited,ans,0);
        return ans;
    }
};