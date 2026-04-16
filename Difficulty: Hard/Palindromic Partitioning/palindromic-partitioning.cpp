// User function Template for C++

class Solution {
  public:
    
    bool isPalindrome(string &s,int i,int j){
        if(i==j){
            return true;
        }
        if(i>j){
            return true;
        }
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
            
        }
        return true;
    };
    
    int solve(string &s,int i, int j,vector<vector<int>>&t){
        //base case
        if(i>=j){
            return 0;
        }
        if(isPalindrome(s,i,j)==true){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int mini=INT_MAX;
        for(int k=i; k<=j-1; k++){
            // int temp_ans=1+solve(s,i,k,t)+solve(s,k+1,j,t);
            // mini=min(mini,temp_ans);
            
                // int left, right;

                // if(t[i][k] != -1){
                //     left = t[i][k];
                // } else {
                //     left = solve(s, i, k, t);
                // }
            
                // if(t[k+1][j] != -1){
                //     right = t[k+1][j];
                // } else {
                //     right = solve(s, k+1, j, t);
                // }
            
                // int temp_ans = 1 + left + right;
                // mini = min(mini, temp_ans);
                
                
                
                if(isPalindrome(s, i, k)){
                int right;
                
                if(t[k+1][j] != -1){
                    right = t[k+1][j];
                } else {
                    right = solve(s, k+1, j, t);
                }
                
                int temp_ans = 1 + right;
                mini = min(mini, temp_ans);
    }

        }
        return t[i][j]=mini;
    }
    int palPartition(string &s) {
        // code here
        int n=s.size();
        vector<vector<int>>t(n+1,vector<int>(n+1,-1));
        int i=0;
        int j=s.length()-1;
        return solve(s,i,j,t);
    }
};