/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int targetSum, long long &sum, int &count) {
        if(root == NULL)
            return;

        sum += root->val;

        if(sum == targetSum)
            count++;

        solve(root->left, targetSum, sum, count);
        solve(root->right, targetSum, sum, count);

        sum -= root->val;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return 0;

        int count = 0;
        long long sum = 0;

        solve(root, targetSum, sum, count);

        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);

        return count;
    }
};