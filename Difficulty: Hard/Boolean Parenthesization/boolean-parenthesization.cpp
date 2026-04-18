// User function Template for C++
class Solution {
  public:
    
    unordered_map<string,int>mp;
    int solve(string &s,int i, int j, bool isTrue){
        
        //base condition
        if(i>j){
            return false;
        }
        if(i==j){
            if(isTrue==true){
                return s[i]=='T';
            }else{
                return s[i]=='F';
            }
        }
        
        //check berfor function call if the value exits in the map or not
        string temp=to_string(i);
        temp.push_back(' ');
        temp.append(to_string(j));
        temp.push_back(' ');
        temp.append(to_string(isTrue));
        if(mp.find(temp)!=mp.end()){
            return mp[temp];
        }
        
        //loop
        int ans =0;
        for(int k=i+1; k<=j-1; k=k+2){
            int lt=solve(s,i,k-1,true);
            int lf=solve(s,i,k-1,false);
            int rt=solve(s,k+1,j,true);
            int rf=solve(s,k+1,j,false);
            
            if(s[k]=='&'){
                if(isTrue==true){
                    ans=ans+lt*rt;
                }else{
                    ans=ans+(lt*rf)+(lf*rt)+(lf*rf);
                }
            }else if(s[k]=='|'){
                if(isTrue==true){
                    ans=ans+(lt*rt)+(lt*rf)+(lf*rt);
                }else{
                    ans=ans+(lf*rf);
                }
            }else{
                if(isTrue==true){
                    ans=ans+(lt*rf)+(lf*rt);
                }else{
                    ans=ans+(lt*rt)+(lf*rf);
                }
            }
        }
        return mp[temp]=ans;
    }
    int countWays(string &s) {
        // code here
        int i=0;
        int j=s.length()-1;
        return solve(s,i,j,true);
    }
};