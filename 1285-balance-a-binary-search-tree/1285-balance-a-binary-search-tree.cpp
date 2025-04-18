/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,vector<int>&ans){
        if(!root) return;
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    TreeNode* inorderToBST(int s, int e, vector<int>&ans){
        if(s>e) return NULL;
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(ans[mid]);
        root->left = inorderToBST(s,mid-1,ans);
        root->right = inorderToBST(mid+1,e,ans);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
    vector<int>ans;
    solve(root,ans);
    return inorderToBST(0,ans.size()-1,ans); 
    }
};