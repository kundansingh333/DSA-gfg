class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        
        int n= arr.size();
        int sum=0;
        
        for(auto it: arr){
            sum+=it;
        }
        
        
        if((sum + diff) % 2 != 0 || diff > sum){
            return 0;
        }
        
        
        int s=(sum+diff)/2;
        
        vector<vector<int>>t(n+1,vector<int>(s+1,0));
        
        t[0][0]=1;
        
        //choice diagram
        for(int i=1; i<t.size(); i++){
            for(int j=0; j<t[0].size(); j++){
                if(arr[i-1]<=j){
                    t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
    
        
        
        return t[n][s];
        
        
    }
};