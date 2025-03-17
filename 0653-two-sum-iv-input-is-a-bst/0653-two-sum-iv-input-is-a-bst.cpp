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
    vector<int>ans;
    void solve(TreeNode* root,vector<int>&ans){
        if(!root) return;
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);

    }
    bool findTarget(TreeNode* root, int k) {
        solve(root,ans);
        int l = 0, r = ans.size()-1;
        while(l < r){
            if(ans[l]+ans[r]==k) return true;
            else if(ans[l]+ans[r] > k) r--;
            else l++;
        }
        return false;
        
    }
};