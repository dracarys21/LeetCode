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
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast) {
            if(slow == fast)
                return true;
            if(fast->next)
                fast = fast->next->next;
            else
                return false;
            slow = slow->next;
        }
        return false;
    }
};