/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int fun(Node* root, int &res){
        if(root==nullptr){
            return 0;
        }
        
        //hypothesis
        int l=fun(root->left,res);
        int r=fun(root->right,res);
        
        //induction
        int temp=max(l,r)+1;
        res=max(res,l+r);
        return temp;
    }
    int diameter(Node* root) {
        // code here
        int res=0;
        fun(root,res);
        return res;
    }
};