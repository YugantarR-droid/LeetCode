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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
        return NULL;

        if(root==p)
        return p;

        if(root==q)
        return q;

        //search in left
        TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);

        //search in right
        TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);

        // 3 cases
        //1) both side is not NULL then root in common ancestor
        if(leftAns!=NULL && rightAns!=NULL)
        return root;

        //2) left side is  NULL right side is not NULL
        else if(leftAns==NULL && rightAns!=NULL)
        return rightAns;

        //3) right side is not NULL left side is NULL
        else return leftAns;



    }
};