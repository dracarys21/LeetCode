/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector <int> postOrder;
        stack <TreeNode*> stck;
        TreeNode *ptr = root;
        if (root == NULL)
            return postOrder;
        do {
            while (ptr != NULL) {
                if (ptr->right != NULL) {
                    stck.push(ptr->right);
                }
                stck.push(ptr);
                ptr = ptr->left;
            }
            ptr = stck.top();
            stck.pop();
            if (ptr->right && !stck.empty() && stck.top() == ptr->right) {
                stck.pop();
                stck.push(ptr);
                ptr = ptr->right;
            }
            else {
                postOrder.push_back(ptr->val);
                ptr = NULL;
            }
        } while(!stck.empty());
        return postOrder;
    }
};