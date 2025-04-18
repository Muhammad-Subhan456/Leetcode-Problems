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
    vector<vector<int>>ans;
    vector<int>a;
    void solve(TreeNode* root){
        if(root==NULL) return;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL); //Separator
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp==NULL){
                ans.push_back(a);
                a.clear();
                if(!q.empty()) q.push(NULL);
            }
            else{
                a.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        solve(root);
        return ans;
        
    }
};