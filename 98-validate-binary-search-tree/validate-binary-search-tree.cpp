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
    bool solve(TreeNode* root,long long lb,long long ub){
        if(root==NULL)
        return true;

        bool currentNode;
        if(root->val>lb && root->val<ub){
            currentNode = true;
        }else{
            currentNode = false;
        }

        bool leftAns = solve(root->left,lb,root->val);
        bool rightAns = solve(root->right,root->val,ub);

        return currentNode && leftAns && rightAns;
    }
    bool isValidBST(TreeNode* root) {
        long long lb = LONG_MIN;
        long long ub = LONG_MAX;

        return solve(root,lb,ub);
    }
};