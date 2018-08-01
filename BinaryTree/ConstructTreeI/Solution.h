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
    
    TreeNode* construct(vector<int>::iterator pStart, vector<int>::iterator pEnd, vector<int>::iterator iStart, vector<int>::iterator iEnd) {
        if (pStart == pEnd) {
            return nullptr;
        }
        if (iStart == iEnd) {
            return nullptr;
        }
        
        auto rootVal = *prev(pEnd);
        auto root = new TreeNode(rootVal);
        auto rootIndex = find(iStart, iEnd, rootVal);
        auto leftLength = distance(iStart, rootIndex);
        
        root->left = construct(pStart, next(pStart, leftLength), iStart, next(iStart, leftLength));
        root->right = construct(next(pStart, leftLength), prev(pEnd), next(rootIndex), iEnd);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return construct(begin(postorder), end(postorder), begin(inorder), end(inorder));
    }
};