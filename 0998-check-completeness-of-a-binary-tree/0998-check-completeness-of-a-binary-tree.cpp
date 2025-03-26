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
    int countNode(TreeNode* tree){
        if(tree==NULL) return 0;
        int ans = 1 + countNode(tree->left) + countNode(tree->right);
        return ans;
       
    }
    bool isCBT(TreeNode* root,int index, int cnt){
        if(root==NULL) return true;
        if(index>=cnt) return false;
        else{
            bool left = isCBT(root->left,(2*index)+1,cnt);
            bool right = isCBT(root->right,(2*index)+2,cnt);
            return (left && right);
        }

    }
    bool isCompleteTree(TreeNode* root) {
        int i =0;
        int count = countNode(root);
        return isCBT(root,i,count);
    }
};