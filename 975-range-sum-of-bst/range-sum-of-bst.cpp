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
    int findSum(TreeNode* root, int low, int high) {
        if(root == NULL)
            return 0;

        int sum = 0;

        if(root->val >= low && root->val <= high) {
            sum += root->val + findSum(root->left,low,high)+findSum(root->right,low,high);
        }

        else if(root->val<low){
            sum += findSum(root->right, low, high);
        }
        else{
            sum += findSum(root->left, low, high);
        }

        return sum;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        return findSum(root, low, high);
    }
};