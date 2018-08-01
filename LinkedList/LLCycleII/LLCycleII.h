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
        if(!head)
            return nullptr;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && slow) {
            if(fast->next)
                fast = fast->next->next;
            else
                return nullptr;
            slow = slow->next;
            if(slow == fast)
                break;
        }
        slow = head;
        while(slow != fast && fast) {
            slow = slow->next;
            fast = fast->next;
        }
        if(fast)
            return slow;
        return nullptr;
    }
};