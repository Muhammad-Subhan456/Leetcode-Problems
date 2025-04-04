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
    void inorder(TreeNode* root, vector<int>&a){
        if(root==NULL) return;
        inorder(root->left,a);
        a.push_back(root->val);
        inorder(root->right,a);
    }

    vector<int> findMode(TreeNode* root) {
    vector<int>a;
    inorder(root,a);
    map<int,int>m;
    int maxi = INT_MIN;
    for(auto e : a){
        m[e]++;
        maxi = max(maxi,m[e]); 
    }
    a.clear();
    for(auto e : m){
        if(e.second==maxi)
            a.push_back(e.first);
    } 
    return a;
    }
};