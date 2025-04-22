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
    vector<int>a;
    vector<int>pre;
    int sum;
    void solve(TreeNode* root){
        if(!root) return;
        solve(root->left);
        a.push_back(root->val);
        solve(root->right);
    }
    void update(TreeNode* &root){
        if(!root) return;
        update(root->left);
        int index = find(a.begin(),a.end(),root->val)-a.begin();
        if(index==0) root->val = sum;
        else{
            root->val = sum - pre[index-1];
        }
        update(root->right);

    }
    TreeNode* bstToGst(TreeNode* root) {
        solve(root);
        pre = a;
        sum= a[0];
        for(int i=1; i < a.size();++i){
        pre[i] = pre[i-1]+pre[i];
        sum += a[i];
        }

      //  for(auto e : pre) cout << e << " ";
       // cout << sum;
        update(root);
        return root;
        
    }
};