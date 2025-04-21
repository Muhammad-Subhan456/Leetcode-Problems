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
    double sum=0,count=0;
    vector<double>ans;
    void solve(TreeNode* root){
        if(root==NULL) return;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL); //Separator
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp==NULL){
               // cout << sum << " " << count << endl;
               // cout << sum/count << endl;
                double a = sum/count;
                ans.push_back(a);
                sum=0,count=0;
                if(!q.empty()) q.push(NULL);
            }
            else{
                sum +=temp->val;
                count++;
                if(temp->left) q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }

    }
    vector<double> averageOfLevels(TreeNode* root) {
            solve(root);
            return ans;
    }
};