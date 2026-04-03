class Solution {
  public:
    vector<vector<int>> t = vector<vector<int>>(1002,vector<int>(1002,-1));
    int fun(vector<int>&wt,vector<int>&val,int W,int n){
        if(n==0 || W==0){
            return 0;
        };
        if(t[n][W]!=-1){
            return t[n][W];
        }
        if(wt[n-1]<=W){
            return t[n][W]= max(val[n-1]+fun(wt,val,W-wt[n-1],n-1),fun(wt,val,W,n-1));
        }else if(wt[n-1]>W){
            return t[n][W] = fun(wt,val,W,n-1);
        }
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        return fun(wt,val,W,n);
        // vector<vector<int>>t(n+1,vector<int>(W+1));
        
        //base condition first row and second row =0
        // for(int i=0; i<t.size(); i++){
        //     for(int j=0; j<t[0].size();j++){
        //         if(i==0 || j==0){
        //             t[i][j]=0;
        //         }
        //     }
        // }
        
        // for(int i=1; i<t.size(); i++){
        //     for(int j=1; j<t[0].size(); j++){
        //         if(wt[i-1]<=j){
        //             t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
                    
        //         }else{
        //             t[i][j]=t[i-1][j];
        //         }
        //     }
        // }
        // return t[n][W];
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};