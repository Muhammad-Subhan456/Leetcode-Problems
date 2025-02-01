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
    vector<string>store;
    void help(TreeNode* root, string s){
        if(!root) return;
        s+= to_string(root->val);
        if(!root->left && !root->right){
            store.push_back(s);
            return;
        }
        s+="->";
        help(root->left,s);
        help(root->right,s);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
    store.clear();
    help(root,"");
    return store;
    }
};