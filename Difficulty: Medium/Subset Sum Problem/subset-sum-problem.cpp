class Solution {
  public:
    vector<vector<int>>t=vector<vector<int>>(202,vector<int>(10002,-1));
    bool fun(vector<int>& arr,int sum,int n){
        //Base condition
        if(n==0 && sum!=0){
            return false;
        }
        if(sum==0){
            return true;
        }
        if(t[n][sum]!=-1){
            return t[n][sum];
        }
        //choice diagram
        if(arr[n-1]<=sum){
            bool first=fun(arr,sum-arr[n-1],n-1);
            bool second=fun(arr,sum,n-1);
            return t[n][sum] =  first || second;
        }else{
            return t[n][sum] = fun(arr,sum,n-1);
        }
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        return fun(arr,sum,n);
        
    }
};