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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode *odd1 = head;
        ListNode *even1 = head->next;
        ListNode *evenHead = head->next;
        while(odd1->next && even1->next) {
            ListNode *odd2 = nullptr;
            ListNode *even2 = nullptr;
            if(odd1->next)
                odd2 = odd1->next->next;
            if(even1->next)
                even2 = even1->next->next;
            odd1->next = odd2;
            even1->next = even2;
            odd1 = odd2;
            even1 = even2;
        }
        odd1->next = evenHead;
        return head;
    }
};