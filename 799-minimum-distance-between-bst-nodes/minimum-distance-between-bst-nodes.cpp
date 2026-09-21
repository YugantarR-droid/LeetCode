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
    void solve(TreeNode* root, TreeNode*& prev, int& ans) {
        if (root == NULL)
            return;

        solve(root->left, prev, ans);

        if (prev != NULL) {
            ans = min(ans, root->val - prev->val);
        }
        prev = root;

        solve(root->right, prev, ans);
    }
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode* prev = NULL;
        solve(root, prev, ans);
        return ans;
    }
};