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
    }
};