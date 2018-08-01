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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return nullptr;
        ListNode *ptr = head;
        ListNode *prev = head;
        while(ptr) {
            ListNode *save = ptr;
            if(ptr->val == val) {
                if(ptr == head) {
                    head = ptr->next;
                    prev = ptr->next;
                    ptr = ptr->next;
                    delete save;
                }
                else {
                    prev->next = ptr->next;
                    ptr = ptr->next;
                    delete save;
                }
            }
            else {
                if(prev != ptr) {
                    prev = prev->next;
                }
                ptr = ptr->next;
            }
        }
        return head;
    }
};