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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptrBehind = head;
        ListNode *ptrAhead = head;
        ListNode*prev = head;
        for(int i = 0; i < n; i++) {
            ptrAhead = ptrAhead->next;
        }
        while(ptrAhead) {
            if(prev->next == ptrBehind)
                prev = prev->next;
            ptrAhead = ptrAhead->next;
            ptrBehind = ptrBehind->next;
        }
        if(ptrBehind == head) {
            head = ptrBehind->next;
        }
        prev->next = ptrBehind->next;
        ptrBehind->next = nullptr;
        delete ptrBehind;
        return head;
    }
};