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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) { return false; }
        return recurse(root, targetSum, 0);
    }
    
private:
    // try all paths
    bool recurse(TreeNode* node, int targetSum, int currentSum) {
        if (node == nullptr ) { return false; }
        
        currentSum += node->val;
        if (currentSum == targetSum && node->left == nullptr && node->right == nullptr) { 
            return true;
        }
        
        return recurse(node->left, targetSum, currentSum) || recurse(node->right, targetSum, currentSum);
    }
};