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
    unordered_set<int> hash;
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) { return false; }
        if (hash.find(root->val) != hash.end()) { 
            return true;
        }
        hash.insert(k - root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};