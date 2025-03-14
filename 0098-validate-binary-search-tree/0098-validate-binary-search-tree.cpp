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
    vector<long long int>ans;
    void valid(TreeNode* root, vector<long long int>&ans){
        if(!root) return;
        valid(root->left,ans);
        ans.push_back(root->val);
        valid(root->right,ans);

    }
    bool isValidBST(TreeNode* root) {
        valid(root,ans);
        for(int i=0 ; i < (ans.size()-1); ++i){
            if(ans[i] >= ans[i+1] ) return false;
        }
        return true;
    }
};