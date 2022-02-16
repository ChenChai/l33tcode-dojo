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
    ListNode* swapPairs(ListNode* head) {
        // recursive solution 
        if (head == nullptr) { return nullptr; }
        else if (head->next == nullptr) { return head; }
        
        ListNode* newHead = head->next;
        
        // Fix up rest of linked list
        newHead->next = swapPairs(newHead->next);
        
        head->next = newHead->next;
        newHead->next = head;
        
        
        return newHead;
        
    }
};