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
    ListNode* middleNode(ListNode* head) {
        int depth  = 0;
        return middleNodeHelper(head, depth);
    }
    
private:
    ListNode* middleNodeHelper(ListNode* current, int &depth) {
        
        if (current == nullptr) { 
            return nullptr;
        }
        int currentDepth = depth;
        depth++;
        ListNode* ans = middleNodeHelper(current->next, depth);
        
        if (currentDepth == (depth) / 2) {
            return current;
        } else {
            return ans;
        }
        
        
    }
};