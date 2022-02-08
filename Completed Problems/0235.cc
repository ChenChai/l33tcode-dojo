/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        helper(root, p, q, ans);
        return ans;
    }

private:
    int helper(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode* &ans) {
        
        if (node == nullptr) { return 0; }
        
        int seenLeft = helper(node->left, p, q, ans);
        int seenRight = helper(node->right, p, q, ans);
        int seenCurrent = node == p || node == q;
        
        if (seenLeft + seenRight + seenCurrent == 2 && ans == nullptr) {
            ans = node;
        } 
        
        return seenLeft + seenRight + seenCurrent;
    }
};