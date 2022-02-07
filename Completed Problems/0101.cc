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
    bool isSymmetric(TreeNode* root) {
        return recurse(root->left, root->right);
    }
private:
    bool recurse(TreeNode* left, TreeNode* right) {
        
        if (left == nullptr && right == nullptr) {
            // empty means symmetric
            return true;
        } else if (left == nullptr || right == nullptr) {
            // one empty only means non symmetric
            return false;
        }
        
        // different values
        if (left->val != right->val) {
            return false;
        }
        
        // check lower nodes
        // checking opposite nodes since we're checking for symmetry around centre!
        return recurse(left->left, right->right) && recurse(right->left, left->right);
    }
};