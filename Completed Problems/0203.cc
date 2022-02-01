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
    ListNode* removeElements(ListNode* head, int val) {
        recurse(head, val);
        return head;
    }
    
private:
    void recurse(ListNode* &node, int val) {
        if (node == nullptr) { return; }
        
        if (node->val == val) {
            node = node->next;
            
            if (node == nullptr) { return; }
            recurse(node, val);
        } else {
            recurse (node->next, val);
        }
    }
};