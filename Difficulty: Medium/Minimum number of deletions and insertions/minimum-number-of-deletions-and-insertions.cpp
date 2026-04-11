class Solution {

  public:
    int minOperations(string &s1, string &s2) {
        // Your code goes here
        int n=s1.length();
        int m=s2.length();
        
        vector<vector<int>> t(n+1, vector<int>(m+1));
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(i==0 || j==0){
                    t[i][j]=0;
                }
            }
        }
        
        //choice diagram
        for(int i=1; i<t.size(); i++){
            for(int j=1; j<t[0].size(); j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        int same=t[n][m];
        int deletion=n-same;
        int insertion=abs(m-same);
        return deletion+insertion;
    }
};