class Solution {
public:
    // Helper function to find the minimum value node in a subtree
    TreeNode* findMin(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);  // Update left child
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key); // Update right child
        } else {
            // Node found
            if (!root->left && !root->right) { // Case 1: No child
                delete root;
                return nullptr;
            } else if (!root->left) { // Case 2: One child (right)
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) { // Case 2: One child (left)
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else { // Case 3: Two children
                TreeNode* temp = findMin(root->right); // Find the inorder successor
                root->val = temp->val; // Copy successor's value
                root->right = deleteNode(root->right, temp->val); // Delete successor
            }
        }
        return root; // Return updated root
    }
};
