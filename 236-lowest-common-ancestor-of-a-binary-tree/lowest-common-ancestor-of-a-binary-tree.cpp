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
        if(root == NULL)
            return NULL;


        //agar pehli node p mil gyi to aage mt dhundo return krdo
        if(root == p)
            return p;
        //agar pehli node q mil gyi to aage mt dhundo return krdo
        if(root == q)
            return q;

        //left se ans nikalo
        TreeNode* leftAns = lowestCommonAncestor(root->left ,p ,q);
        //right se ans nikalo
        TreeNode* rightAns = lowestCommonAncestor(root->right, p,q);

        //3 case banege

        //1) left se non null aya ho aur right se non null aya ho to current node he ans hoga
        if(leftAns != NULL && rightAns != NULL)
        return root;

        //2) left se non null aya ho aur right se  null aya ho to left node he ans hoga
        else if(leftAns!= NULL && rightAns == NULL)
        return leftAns;

        //2) right se non null aya ho aur left se  null aya ho to right node he ans hoga
        else
        return rightAns;
    }
};