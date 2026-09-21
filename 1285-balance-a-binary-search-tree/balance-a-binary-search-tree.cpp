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
    TreeNode* builtTree(vector<int> inorder,int s,int e){
        
        if(s>e)
        return NULL;

        int m = (s+(e-s)/2);
        int element = inorder[m];

        TreeNode* root = new TreeNode(element);

        root->left=builtTree(inorder,s,m-1);
        root->right=builtTree(inorder,m+1,e);

        return root;

    }
    void storeInorder(TreeNode* root,vector<int>& inorder){
        if(root==NULL)
        return;

        storeInorder(root->left,inorder);
        inorder.push_back(root->val);
        storeInorder(root->right,inorder);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        storeInorder(root,inorder);
        int s=0;
        int e=inorder.size()-1;

        return builtTree(inorder,s,e);

    }
};