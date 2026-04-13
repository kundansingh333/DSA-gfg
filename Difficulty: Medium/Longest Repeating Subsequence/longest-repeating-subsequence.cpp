class Solution {
  public:
    int LongestRepeatingSubsequence(string &s) {
        // Code here
        int n=s.length();
        string a=s;
        string b=s;
        
        vector<vector<int>>t(n+1,vector<int>(n+1));
        //initialization
        for(int i=0; i<n+1; i++){
            for(int j=0; j<n+1; j++){
                if(i==0 || j==0){
                    t[i][j]=0;
                    
                }
            }
        }
        
        //choice diagram
        
        for(int i=1; i<t.size(); i++){
            for(int j=1; j<t[0].size(); j++){
                if(a[i-1]== b[j-1] && i!=j){
                    t[i][j]=t[i-1][j-1]+1;
                }else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        return t[n][n];
        
        
        
    }
};