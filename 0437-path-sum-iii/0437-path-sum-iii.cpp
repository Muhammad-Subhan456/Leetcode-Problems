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
    void solve(TreeNode* root,int targetSum,long long &count,vector<long long>&path){
        if(root==NULL) return;
        path.push_back(root->val);
        solve(root->left,targetSum,count,path);
        solve(root->right,targetSum,count,path);
        long long sum=0;
        for(long long i=path.size()-1; i >= 0; --i){
            sum += path[i];
            if(sum==targetSum) count++;
        }
        path.pop_back();
    } 
    int pathSum(TreeNode* root, int targetSum) {
        vector<long long>path;
        long long count=0;
        solve(root,targetSum,count,path);
        return count;
    }
};