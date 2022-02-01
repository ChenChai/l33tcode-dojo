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
    ListNode* deleteMiddle(ListNode* head) {
        recurse(head, 0);
        return head;
    }
    
private:
    int recurse(ListNode* &node, int depth) {
        if (node == nullptr) {
            return depth;
        }
        
        int totalDepth = recurse(node->next, depth + 1);
        int indexToDelete = totalDepth / 2;
        
        if (depth == indexToDelete) {
            node = node->next;
        }
        
        return totalDepth;
    }
};