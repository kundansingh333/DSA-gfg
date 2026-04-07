// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        int N=n;
        vector<int> len;
        for(int i=1; i<=n; i++){
            len.push_back(i);
        };
        
        vector<vector<int>>t(n+1,vector<int>(N+1));
        
        //base case
        
        for(int i=0; i<n+1; i++){
            for(int j=0; j<N+1; j++){
                if(i==0 || j==0){
                    t[i][j]=0;
                }
            }
        }
        // choice diagram
        for(int i=1; i<n+1; i++){
            for(int j=1; j<N+1; j++){
                if(len[i-1]<=j){
                    t[i][j]=max(price[i-1]+t[i][j-len[i-1]],t[i-1][j]);
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][N];
        
    }
};