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
    void reorderList(ListNode* head) {
        
        stack<ListNode*> nodes;
        ListNode* current = head;
        while(current != nullptr) {
            nodes.push(current);
            current = current->next;
        }
        
        int half = nodes.size() / 2;
        
        current = head;
        for (int i = 0; i < half; i++) {
            ListNode* temp = current->next;
            current->next = nodes.top();
            
            nodes.pop();
            
            current->next->next = temp;
            current = current->next->next;
        }
        current-> next = nullptr;
    }
};