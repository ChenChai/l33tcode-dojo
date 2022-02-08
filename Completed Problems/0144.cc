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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        recurse(root, ans);
        return ans;
    }
    
private: 
    void recurse(TreeNode* root, vector<int> & ans) {
        
        if (root == nullptr) { return; }
        
        ans.push_back(root->val);
        
        recurse(root->left, ans);
        recurse(root->right, ans);
        
    }
};