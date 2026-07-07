class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
    
private:
    int checkHeight(TreeNode* node) {
        if (!node) return 0;
        
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1;  // left subtree unbalanced
        
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1;  // right subtree unbalanced
        
        if (abs(leftHeight - rightHeight) > 1) return -1;  // this node unbalanced
        
        return max(leftHeight, rightHeight) + 1;
    }
};