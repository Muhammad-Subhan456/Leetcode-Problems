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
    bool isSymmetric(TreeNode* root, TreeNode* subRoot){
        if((root==NULL && subRoot!=NULL) || (root!=NULL && subRoot==NULL)) return false;
        if(root==NULL && subRoot == NULL) return true;
        if(root->val != subRoot->val) return false;
        return isSymmetric(root->left,subRoot->left) && isSymmetric(root->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(root->val == subRoot->val){
            bool ans = isSymmetric(root,subRoot);
            if(ans) return true;
        }

        bool left = isSubtree(root->left,subRoot);
        bool right = isSubtree(root->right,subRoot);
        return left || right;
    }
};