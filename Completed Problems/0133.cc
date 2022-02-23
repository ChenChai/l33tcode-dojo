/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> cloned;
        return cloneGraphHelper(cloned, node);
    }
    
private:
    // hash map cloned contains already-cloned nodes, first index 
    // is original pointer, second index is new pointer to deep cloned node
    Node* cloneGraphHelper(unordered_map<Node*, Node*>& cloned, Node* node) {
        if (cloned.find(node) != cloned.end()) {
            // Already cloned, return cloned copy
            return cloned[node];
        }
        
        if (node == nullptr) { return nullptr; }
        
        // Node hasn't been cloned yet!
        // Make a new copy
        Node* newNode = new Node(node->val);
        
        // Register in map
        cloned[node] = newNode;
        
        // Add Neighbouring nodes
        for (Node* neighbor : node->neighbors) {
            newNode->neighbors.push_back(cloneGraphHelper(cloned, neighbor));
        }
        
        return newNode;
    }
};
