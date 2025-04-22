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
    bool solve(TreeNode* root, int n){
        if(!root) return true;
        if(root->val != n) return false;
        bool l = solve(root->left,n);
        bool r = solve(root->right,n);
        return (l&&r);
        
    }

    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        int n = root->val;
        return solve(root,n);
        

    }
};