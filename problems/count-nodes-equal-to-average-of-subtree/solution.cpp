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
private:
    int solve(TreeNode* root, int& nodeCount, int& ans) {
        if(root == nullptr) {
            nodeCount = 0;
            return 0;
        }

        int leftCount = 0, rightCount = 0;

        int leftSum = solve(root->left, leftCount, ans);
        int rightSum = solve(root->right, rightCount, ans);

        int totalSum = leftSum + rightSum + root->val;
        nodeCount = leftCount + rightCount + 1;

        if(totalSum / nodeCount == root->val) {
            ans++;
        }

        return totalSum;
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        int dummyCount = 0;
        solve(root, dummyCount, ans);
        return ans;
    }
};