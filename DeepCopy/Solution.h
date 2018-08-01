/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return nullptr;
        RandomListNode *it1 = head->next;
        map<RandomListNode*, RandomListNode*> q;
        RandomListNode *head2 = new RandomListNode(head->label);
        RandomListNode *it2 = head2;
        q.insert(pair<RandomListNode*, RandomListNode*>(head, head2));
        while(it1) {
            RandomListNode *newNode = new RandomListNode(it1->label);
            it2->next = newNode;
            q.insert(pair<RandomListNode*, RandomListNode*>(it1, newNode));
            it1 = it1->next;
            it2 = it2->next;
        }
        map<RandomListNode*, RandomListNode*>::iterator i;
        for (i = q.begin(); i != q.end(); i++) {
            if(i->first->random) {
                i->second->random = q[i->first->random];
            }
        }
        return head2;
    }
};