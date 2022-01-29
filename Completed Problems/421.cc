struct Node {
    public:
        Node* nextZero = nullptr;
        Node* nextOne = nullptr;
        int finalVal = -1; // represents the final value of the node, only relevant for leaf node and convenience
};

// Stores values as 1/0 in binary
class Trie {
    Node* head = new Node();
    public: 
        Node* getHead() {
            return head;
        }
    
    
        void insert(int num) {
            Node* current = head;
            for (int i = 31; i >= 0; i--) {
                // Check each of the bits in order from most to least significant
                if ((num & (1 << i)) != 0) {
                    // Digit is a 1
                    
                    if (current->nextOne == nullptr) {
                        current->nextOne = new Node();
                    }
                    
                    current = current->nextOne;
                } else {
                    // digit is a 0
                    if (current->nextZero == nullptr) {
                        current->nextZero = new Node();
                    }
                    
                    current = current->nextZero;
                }
            }
            
            current->finalVal = num;
        }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        Trie trie;
        for (auto num : nums) {
            trie.insert(num);
        }
        
        Node* current = trie.getHead();
        
        // Get to first node where both child nodes exist.
        while (current->nextOne == nullptr || current->nextZero == nullptr) {
            // If there are no ones or zeroes then welp there aren't any values in the trie lol
            // or they're all zero
            if (current->nextZero == nullptr && current->nextOne == nullptr) { return 0; }
            
            // Go down the tree 
            current = current->nextZero == nullptr ? current->nextOne : current->nextZero;
        }        
        // acquire first number (biggest possible leading sig dig) 
        Node* first = current->nextOne;
        
        // Second number (to be biggest) must have a zero at that leading sig dig location
        Node* second = current->nextZero;
        
        // Continue by navigating down trie, using divide and conquer
        
                
        return divConquer(first, second);
    }
    
private:
    int divConquer(Node* first, Node* second) {
        
        // can't keep going since one of the nodes is non-existent
        if (first == nullptr || second == nullptr) { return 0;}
        if (first->finalVal != -1) {
            // we've hit leaf nodes
            return first->finalVal ^ second->finalVal;
        }
        int optimal = max(
                            divConquer(first->nextOne, second->nextZero),
                            divConquer(first->nextZero, second->nextOne)
                         );
        
        // Only if suboptimal options are available should we resort
        // to cancelled-out values.
        if (optimal == 0) {
            optimal = max(
                            divConquer(first->nextOne, second->nextOne), 
                            divConquer(first->nextZero, second->nextZero)
            );
        }
        
        return optimal;
    }
};