/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return nullptr;
        stack<Node*> st;
        Node *it = head;
        do {
            if(!st.empty()) {
                Node *top = st.top();
                st.pop();
                it->next = top;
                top->prev = it;
            }
            while(it->next || it->child) {
                if(it->child) {
                    if(it->next)
                        st.push(it->next);
                    it->next = it->child;
                    it->child->prev = it;
                    it->child = NULL;
                }
                it = it->next;
            }
        } while(!st.empty());
        return head;
    }
};