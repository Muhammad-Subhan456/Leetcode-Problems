class Solution {
public:
    int helper(TreeNode* root, int ans, int curMax){
        if(!root) return 0;
        int rootans = 0;
        if(root->val >= curMax){
            rootans = 1;
            curMax = root->val;
        }
        int lans = helper(root->left,ans,curMax);
        int rans = helper(root->right,ans,curMax);
        return lans+rans+rootans;

    }   
    int goodNodes(TreeNode* root) {
        return helper(root,0, INT_MIN);
    }
};