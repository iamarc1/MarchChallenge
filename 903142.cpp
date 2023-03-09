/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow) {
                ListNode* entry = head;
                while(slow != entry) {
                  
                    slow = slow -> next;
                    entry = entry -> next;
                }
                
                return entry;
            }
        }
        return NULL;  
    }
};
