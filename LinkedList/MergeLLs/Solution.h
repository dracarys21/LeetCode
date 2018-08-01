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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode *ptr1 = l1;
        ListNode *ptr2 = l2;
        ListNode *head = nullptr;
        if(ptr1->val < ptr2->val) {
            head = ptr1;
            ptr1 = ptr1->next;
        }
        else {
            head = ptr2;
            ptr2 = ptr2->next;
        }
        ListNode *it = head;
        while(ptr1 && ptr2) {
            if(ptr1->val < ptr2->val) {
                it->next = ptr1;
                it = ptr1;
                ptr1 = ptr1->next;
            }
            else {
                it->next = ptr2;
                it = ptr2;
                ptr2 = ptr2->next;
            }
        }
        it->next = ptr1 ? ptr1 : (ptr2 ? ptr2 : nullptr);
        return head;
    }
};