/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> cloned;
        return helper(cloned, head);
    }
    
private:
    // returns the deep copy of the node given, creating 
    // one if it doesn't exist.
    Node* helper(unordered_map<Node*, Node*> &cloned, Node* node) {
        if (node == nullptr) {
            // end of the list
            return nullptr;
        }
        
        if (cloned.find(node) != cloned.end()) {
            return cloned[node];
        }
        
        Node* newNode = new Node(node->val);
        cloned[node] = newNode;

        newNode->next = helper(cloned, node->next);
        newNode->random = helper(cloned, node->random);
        
        return newNode;
    }
};
