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
     int maxDepth(TreeNode* root) {
        if(root==NULL)
        return 0;

        int leftAns = maxDepth(root->left) + 1;
        int rightAns = maxDepth(root->right) + 1;

        return max(leftAns,rightAns);
        
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        return true;

        //calculate height of one left and right tree node
        int leftHeight=maxDepth(root->left);
        int rightHeight=maxDepth(root->right);
        //check differcence 
        int absDiff = abs(leftHeight-rightHeight);
        //if greater return false
        if(absDiff>1){
            return false;
        }else{
        //recursion sambhal lega
            return isBalanced(root->left) && isBalanced(root->right);
        }
    }
};