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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        helper(ans, root, 0);
        return ans;
    }
    
private:
    void helper(vector<vector<int> >& ans, TreeNode* node, int level) {
        if (node == nullptr) { return; }
        
        while (ans.size() <= level) {
            ans.push_back({});
        }
        
        ans[level].push_back(node->val);
        
        helper(ans, node->left, level + 1);
        helper(ans, node->right, level + 1);
    }
        
        
};