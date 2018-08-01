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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelOrder;
        queue<vector<TreeNode*>> q;
        if (root) {
            q.push({root});
        }
        while(!q.empty()) {
            vector<TreeNode*> level = q.front();
            q.pop();
            vector<int> levelValues;
            vector<TreeNode*> levelPointers;
            for (TreeNode* ptr : level) {
                levelValues.push_back(ptr->val);
                if (ptr->left)
                    levelPointers.push_back(ptr->left);
                if (ptr->right)
                    levelPointers.push_back(ptr->right);
            }
            if (!levelValues.empty())
                levelOrder.push_back(levelValues);
            if(!levelPointers.empty()){
                q.push(levelPointers);
            }
        }
        return levelOrder;
    }
};