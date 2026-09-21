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
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==element){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder,
                    int inorderStart, int inorderEnd, int& postorderIndex) {
        if (postorderIndex<0)
            return NULL;

        if (inorderStart > inorderEnd)
            return NULL;

        int postorderElement = postorder[postorderIndex];
        postorderIndex--;
        int searchedIndexInorder = getIndex(postorderElement,inorder);
        int inorderElement = inorder[searchedIndexInorder];

        TreeNode* root = new TreeNode(inorderElement);

        //yaha galti hogi pehle right ki call krna hai
        root->right = solve(postorder, inorder, searchedIndexInorder + 1,
                            inorderEnd, postorderIndex);

        root->left = solve(postorder, inorder, inorderStart,
                           searchedIndexInorder - 1, postorderIndex);
        

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;
        int postorderIndex = postorder.size()-1;
        return solve(postorder, inorder, inorderStart, inorderEnd,
                     postorderIndex);
    }
};