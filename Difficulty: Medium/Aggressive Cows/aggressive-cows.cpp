class Solution {
  public:
    bool isPossible(vector<int> &stalls,int k, int n, int mid){
        int cows=1;
        int prev=stalls[0];
        for(int i=1; i<n; i++){
            int dist=stalls[i]-prev;
            if(dist<mid){
                continue;
            }else{
                cows++;
                prev=stalls[i]; 
            }
            
        }
        if(cows>=k){
            return true;
        }else{
            return false;
        }
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls[n-1]-stalls[0];
        int res=-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(stalls,k,n,mid)){
                res=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
            
        }
        return res;
        
    }
};