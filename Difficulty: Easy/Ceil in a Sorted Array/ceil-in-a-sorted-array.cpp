// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int low=0;
        int high=arr.size()-1;
        int res=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]<x){
                low=mid+1;
            }else{
                res=mid;
                high=mid-1;
            }
        }
        return res;
    }
};