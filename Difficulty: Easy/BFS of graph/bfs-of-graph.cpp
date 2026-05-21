class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int>ans;
        queue<int>q;
        int n=adj.size();
        vector<bool>visited(n,0);
        q.push(0);
        visited[0]=1;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            ans.push_back(f);
            for(auto nbr:adj[f]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=1;
                }
            }
        }
        return ans;
    }
};