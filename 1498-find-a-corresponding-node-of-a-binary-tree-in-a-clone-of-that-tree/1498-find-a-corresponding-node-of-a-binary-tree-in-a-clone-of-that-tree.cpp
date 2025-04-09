/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void solve(TreeNode* o, TreeNode* c, TreeNode* t, TreeNode* &answer){
        if(!o) return;
        if(o->val == t->val){
            answer = c;
            return;
        }
        solve(o->left,c->left,t,answer);
        solve(o->right,c->right,t,answer);

    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* answer;
        solve(original,cloned,target,answer);
        return answer;

    }
};