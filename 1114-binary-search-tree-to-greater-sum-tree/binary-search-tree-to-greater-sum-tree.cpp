/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(TreeNode*& root, vector<int>& inorder, int& index) {
        if (root == NULL)
            return NULL;

        // left call
        root->left = buildTree(root->left, inorder, index);
        // current Node
        root->val = inorder[index];
        index++;
        // right call
        root->right = buildTree(root->right, inorder, index);

        return root;
    }
    void storeInorder(TreeNode* root, vector<int>& inorder) {
        if (root == NULL)
            return;

        // L
        storeInorder(root->left, inorder);
        // N
        inorder.push_back(root->val);
        // R
        storeInorder(root->right, inorder);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> inorder;
        storeInorder(root, inorder);
        int j = inorder.size() - 1;
        int i = inorder.size() - 2;
        int index = 0;
        while (i >= 0) {
            inorder[i] = inorder[i] + inorder[j];
            i--;
            j--;
        }
        root = buildTree(root, inorder, index);
        return root;
    }
};