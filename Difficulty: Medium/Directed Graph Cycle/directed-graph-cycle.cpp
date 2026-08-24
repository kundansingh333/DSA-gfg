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
    
    bool topoSort(vector<vector<int>>&adj,int V){
        vector<int>indegree(V,0);
        for(int i=0; i<V; i++){
            for(auto &x:adj[i]){
                indegree[x]+=1;
            }
        }
        queue<int>q;
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            ans.push_back(f);
            for(auto &nbr:adj[f]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        return ans.size()!=V;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto edge:edges){
            int a=edge[0];
            int b=edge[1];
            adj[a].push_back(b);
        }
        // vector<bool>visited(V,false);
        // vector<int>current_path(V,0);
        // for(int i=0; i<V; i++){
        //     if(!visited[i]){
        //         bool ans=fun(i,adj,visited,current_path);
        //         if(ans) return true;
        //     }
        // }
        // return false;
        
        
        
        //topologica sort
        bool ans=topoSort(adj,V);
        return ans;
        
        
        
    }
};