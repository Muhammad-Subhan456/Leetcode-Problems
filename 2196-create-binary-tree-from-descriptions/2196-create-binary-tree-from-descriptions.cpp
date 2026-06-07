/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        set<int> child;
        map<int,TreeNode*>mp;
        for (auto& r : d) {
            child.insert(r[1]);
            TreeNode* node = new TreeNode(r[1]);
            mp[r[1]] = node;
        }

        TreeNode* root = nullptr;

        for (auto& r : d) {
            if (child.find(r[0]) == child.end()) {
                root = new TreeNode(r[0]);
                break;
            }
        }

        for(auto &r : d){
            if(r[0] == root->val){
                if(r[2] == 1){
                    root->left = mp[r[1]];
                }
                else root->right = mp[r[1]];
            }
            else if(r[2] == 1){
                mp[r[0]]->left = mp[r[1]];
            }
            else{
                mp[r[0]]->right = mp[r[1]];
            }
        }
        return root;

    }
};