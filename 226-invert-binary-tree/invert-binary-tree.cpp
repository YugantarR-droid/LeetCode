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
    void solve(TreeNode* root,TreeNode* leftNode,TreeNode* rightNode){

        if(root==NULL)
        return ;

        leftNode=root->left;
        rightNode=root->right;

        root->left = rightNode;
        root->right = leftNode;

        solve(root->left,leftNode,rightNode);
        solve(root->right,leftNode,rightNode);

        
    }
    TreeNode* invertTree(TreeNode* root) {

        if(root==NULL){
            return NULL;
        }

        TreeNode* leftNode = NULL;
        TreeNode* rightNode = NULL;

        solve(root,leftNode,rightNode);

        return root;


    }
};