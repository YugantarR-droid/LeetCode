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
    void updateTree(TreeNode* root,vector<int> &inorder,int& inorderIndex){
        if(root==NULL)
        return;

        updateTree(root->left,inorder,inorderIndex);
        root->val=inorder[inorderIndex];
        inorderIndex++;
        updateTree(root->right,inorder,inorderIndex);
    }

    void genrateInorder(TreeNode* root,vector<int> &inorder){
        if(root==NULL)
        return;
        genrateInorder(root->left,inorder);
        inorder.push_back(root->val);
        genrateInorder(root->right,inorder);
    }
    TreeNode* convertBST(TreeNode* root) {
        vector<int> inorder;
        genrateInorder(root,inorder);
        int n=inorder.size();
        int inorderIndex=0;
        int i=n-2;
        int j=n-1;
        while(i>=0){
            inorder[i]=inorder[i]+inorder[j];
            i--;
            j--;
        }

        updateTree(root,inorder,inorderIndex);
        return root;


    }
};