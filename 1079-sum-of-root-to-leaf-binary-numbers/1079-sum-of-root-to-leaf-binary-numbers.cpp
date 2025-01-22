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
    vector<string> str;
    
    void solve(TreeNode* root, string s){
        if(root == NULL) return;

        if(!root->left && !root->right){
            str.push_back(s + to_string(root->val));
            return;
        }
        s += (root->val + '0');
        solve(root->left, s);
        solve(root->right, s);
    }
    int sum(string s){
        int res=0;
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();++i){
            res += (s[i]-'0')*pow(2,i);
        }
        return res;
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans=0;
        string s = "";
        solve(root, s);
        for(string s : str){
            ans += sum(s);
        }
        return ans;
    }
};