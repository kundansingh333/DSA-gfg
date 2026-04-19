// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    unordered_map<string, bool>mp;
    bool solve(string a,string b){
        if(a.compare(b)==0){
            return true;
        }
        if(a.length()<=1){
            return false;
        }
        int n=a.length();
        //make the key
        string key=a;
        key.push_back(' ');
        key.append(b);
        
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }
        
        bool flag=false;
        for(int i=1; i<=n-1; i++){
            //if swapped
            bool c1=solve(a.substr(0,i),b.substr(n-i,i))==true && solve(a.substr(i,n-i),b.substr(0,n-i))==true;
            // if not swapped
            bool c2=solve(a.substr(0,i),b.substr(0,i)) == true && solve(a.substr(i,n-i),b.substr(i,n-i))==true;
            if(c1 || c2){
                flag=true;
                break;
            }
        }
        return mp[key]=flag;
    }
    bool isScramble(string S1, string S2) {
        // code here
        if(S1.length()!=S2.length()){
            return false;
        }
        if(S1.length()==0 && S2.length()==0){
            return true;
        }
        return solve(S1,S2);
    }
};
