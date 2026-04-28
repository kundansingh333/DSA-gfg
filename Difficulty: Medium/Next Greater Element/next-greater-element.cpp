class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        // int n=arr.size();
        // vector<int>ans(n,-1);
        // for(int i=0; i<n-1; i++){
        //     for(int j=i+1; j<n; j++){
        //         if(arr[j]>arr[i]){
        //             ans[i]=arr[j];
        //             break;
        //         }
        //     }
        // }
        // return ans;
        
        
        vector<int>ans;
        stack<int>st;
        
        int n=arr.size();
        for(int i=n-1; i>=0; i--){
            if(st.size()==0){
                ans.push_back(-1);
            }else if(st.size()>0 && st.top()>arr[i]){
                ans.push_back(st.top());
            }else if(st.size()>0 && st.top()<=arr[i]){
                while(st.size()>0 && st.top()<=arr[i]){
                    st.pop();
                }
                if(st.size()==0){
                    ans.push_back(-1);
                }else{
                    ans.push_back(st.top());
                }
            }
            st.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};