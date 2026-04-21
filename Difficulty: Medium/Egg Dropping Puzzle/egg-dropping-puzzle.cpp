class Solution {
  public:

    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    
    // vector<vector<int>> t=vector<vector<int>>(10001,vector<int>(10001,-1));
    int solve(int n,int k,vector<vector<int>>&t){
        if(k==0 || k==1){
            return k;
        }
        if(n==1){
            return k;
        }
        
        if(t[n][k]!=-1){
            return t[n][k];
        }
        
        int mini=INT_MAX;
        // for(int x=1; x<=k; x++){
        //     int temp_ans=1+max(solve(n-1,x-1,t),solve(n,k-x,t));
        //     mini=min(mini,temp_ans);
        // }
        int low=1;
        int high=k;
        while(low<=high){
            int mid=low+(high-low)/2;
            int left=solve(n-1,mid-1,t);//egg breaks
            int right=solve(n,k-mid,t);//egg survives
            int temp_ans=1+max(left,right);
            mini=min(mini,temp_ans);
            if(left>right){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        
        
        
        
        
        
        
        
        return t[n][k]= mini;
    }
    int eggDrop(int n, int k) {
        // code here
        vector<vector<int>>t(n+1,vector<int>(k+1,-1));
        return solve(n,k,t);
    }
};