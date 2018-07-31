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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;
        int count1 = 0;
        int count2 = 0;
        while(ptr1) {
            ptr1 = ptr1->next;
            count1++;
        }
        while(ptr2) {
            ptr2 = ptr2->next;
            count2++;
        }
        ptr1 = headA;
        ptr2 = headB;
        if(count1 > count2) {
            for(int i = 0; i < count1 - count2; i++) {
                ptr1 = ptr1->next;
            }
        }
        else {
            for(int i = 0; i < count2 - count1; i++) {
                ptr2 = ptr2->next;
            }
        }
        while(ptr1 && ptr2) {
            if(ptr1 == ptr2)
                return ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return nullptr;
    }
};