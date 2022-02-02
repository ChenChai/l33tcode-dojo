/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        recurse(root, nullptr);
        return root;
    }
    
private:
    // connects all nodes beneath it, but not itself.
    void recurse(Node* node, Node* right) {
        if (node == nullptr || node->right == nullptr) {
            // leaf node, we're done!
            return;
        }
        // connect nodes directly underneath
        node->left->next = node->right;
        node->right->next = right != nullptr ? right->left : right;
        
        recurse(node->left, node->right);

        recurse(node->right, right == nullptr ? right : right->left);
    }
};