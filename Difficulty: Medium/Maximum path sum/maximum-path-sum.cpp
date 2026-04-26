/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int solve(Node* root,int &res){
        //base case
        if(root==nullptr){
            return 0;
        }
        //hyphotesis
        int left=solve(root->left,res);
        int right=solve(root->right,res);
        
        //induction
        
        int temp=max(max(left,right)+root->data,root->data);
        int ans=max(temp,left+right+root->data);
        res=max(res,ans);
        return temp;
        
        
    }
    int findMaxSum(Node *root) {
        // code here
        int res=INT_MIN;
        solve(root,res);
        return res;
    }
};