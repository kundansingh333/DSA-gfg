class Solution {
  public:
    
    vector<vector<int>>t=vector<vector<int>>(1002,vector<int>(1002,-1));
    int fun(vector<int>&arr,int target,int n){
        if(n==0){
            if(target==0){
                return 1;
            }else{
                return 0;
            }
        }
        if(t[n][target]!=-1){
            return t[n][target];
        }
        
        
        if(arr[n-1]<=target){
            int a=fun(arr,target-arr[n-1],n-1);
            int b=fun(arr,target,n-1);
            return t[n][target] = a+b;
        }else{
            return t[n][target] = fun(arr,target,n-1);
        }
    }
  
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        return fun(arr,target,n);
    }
};