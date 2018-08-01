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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        stack<TreeNode*> stck;
        if (root != NULL) {
            stck.push(root);
            preOrder.push_back(root->val);
            TreeNode *ptr = root;
            while (!stck.empty()) {
                while(ptr->left != NULL) {
                    preOrder.push_back(ptr->left->val);
                    stck.push(ptr->left);
                    ptr = ptr->left;
                }
                if (!stck.empty()) {
                    TreeNode *top = stck.top();
                    stck.pop();
                    if (top->right != NULL) {
                        stck.push(top->right);
                        preOrder.push_back(top->right->val);
                        ptr = top->right;
                    }
                }
            }
        }
        return preOrder;
    }
};