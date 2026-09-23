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
    int getIndex(int element,vector<int> inorder){
        for(int i =0; i<inorder.size();i++){
            if(inorder[i]==element){
                return i;
            }
        }
        return -1;

    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &preorderIndex,int inorderStart,int inorderEnd){
        if(inorderStart > inorderEnd)
        return NULL;

        if(preorderIndex == preorder.size())
        return NULL;

        int element = preorder[preorderIndex];
        preorderIndex++;
        int elementIndex = getIndex(element,inorder);

        TreeNode* root = new TreeNode(element);

        root->left =  solve(preorder,inorder,preorderIndex,inorderStart,elementIndex-1);

        root->right = solve(preorder,inorder,preorderIndex,elementIndex+1,inorderEnd);

        return root;

        }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;
        
        return solve(preorder,inorder,preorderIndex,inorderStart,inorderEnd);
    }
};