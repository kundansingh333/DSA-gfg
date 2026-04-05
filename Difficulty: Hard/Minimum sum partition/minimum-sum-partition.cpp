class Solution {
  public:
    
    int minDifference(vector<int>& arr) {
        // code here
        int n= arr.size();
        int sum=0;
        for(auto it:arr){
            sum+=it;
        }
        vector<vector<int>>t(n+1,vector<int>(sum+1));
        
        //intialization
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(i==0){
                    t[i][j]=0;
                }
                if(j==0){
                    t[i][j]=1;
                }
            }
        }
        
        //choice diagram
        
        for(int i=1; i<t.size(); i++){
            for(int j=1; j<t[0].size(); j++){
                if(arr[i-1]<=j){
                    t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        vector<int>range;
        int s=sum/2;
        for(int i=0; i<=s; i++){
            if(t[n][i]==1){
                range.push_back(i);
            }
        }
        int mn=INT_MAX;
        for(int i=0; i<range.size(); i++){
            int valid=sum-(2*range[i]);
            mn=min(mn,valid);
        }
        return mn;
        
    }
};
