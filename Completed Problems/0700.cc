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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) { return nullptr; }
        

        if (root->val > val) {
            // search value is less
            return searchBST(root->left, val);
        } else if (root->val < val) {
            return searchBST(root->right, val);
        } else {
            // equal--I have a theory putting the equal clause
            // down here makes it run faster since it's checked less lol
            return root;
        }
        
    }
};