class Solution {
  public:
    vector<vector<int>>t=vector<vector<int>>(201,vector<int>(201,-1));
    int solve(vector<int>&arr,int i,int j){
        if(i>=j){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int mini=INT_MAX;
        for(int k=i; k<=j-1; k++){
            int temp_ans=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
            mini=min(mini,temp_ans);
        }
        return t[i][j]=mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int i=1;
        int j=arr.size()-1;
        return solve(arr,i,j);
    }
};