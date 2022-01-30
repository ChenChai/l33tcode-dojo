/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int depth = 1;
        // Assume head not null
        recursiveHelper(head, depth, n);
        return head;
    }
    
private:
    void recursiveHelper(ListNode* &current, int& depth, int n) {
        if (current == nullptr) { return; }
        
        int currentDepth = depth;
        
        depth++;
        recursiveHelper(current->next, depth, n);
         
        if ((depth - currentDepth) == n) {
            // modify using reference, removing node
            current = current->next;
        }       
    }
};