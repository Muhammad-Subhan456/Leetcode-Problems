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
    void valid(TreeNode* root, vector<int>&ans){
        if(!root) return;
        valid(root->left,ans);
        ans.push_back(root->val);
        valid(root->right,ans);

    }
    int kthSmallest(TreeNode* root, int k) {
        valid(root,ans);
        int a =ans[k-1];
        return a;
    }
};