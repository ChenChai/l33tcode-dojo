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
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MIN, INT_MAX, false, false);
    }
    
private:
    bool helper(TreeNode* root, int lower, int higher, int minValid, int maxValid) {
        if (root == nullptr) { return true; }
        
        if ((minValid && root->val <= lower) || (maxValid && root->val >= higher)) {
            return false;
        }
        
        return helper(root->right, root->val, higher, true, maxValid) 
            && helper(root->left, lower, root->val, minValid, true);
        
    }
};