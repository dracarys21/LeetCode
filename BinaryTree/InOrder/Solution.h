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
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> inOrder;
        stack<TreeNode*> stck;
        if (root != NULL) { //Start with the root node
            stck.push(root);
        }
        TreeNode *ptr = root;
        while(!stck.empty()) {
            while (ptr->left != NULL) {
                stck.push(ptr->left);
                ptr = ptr->left;
            }
            TreeNode *top = stck.top();
            stck.pop();
            inOrder.push_back(top->val);
            if (top->right != NULL) {
                stck.push(top->right);
                ptr = top->right;
            }
        }
        return inOrder;
    }
};