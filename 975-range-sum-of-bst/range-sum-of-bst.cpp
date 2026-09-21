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
    // int findSum(TreeNode* root, int low, int high) {
    //     if(root == NULL)
    //         return 0;

    //     int sum = 0;

    //     if(root->val >= low && root->val <= high) {
    //         sum += root->val + findSum(root->left,low,high)+findSum(root->right,low,high);
    //     }

    //     else if(root->val<low){
    //         sum += findSum(root->right, low, high);
    //     }
    //     else{
    //         sum += findSum(root->left, low, high);
    //     }

    //     return sum;
    // }

    int rangeSumBST(TreeNode* root, int low, int high) {
         if(root == NULL)
            return 0;

        //sum ko 0 se initialize kro
        int sum = 0;

        //afar within range valuse hai to add kro aur left right me search kro
        if(root->val >= low && root->val <= high) {
            sum += root->val + rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
        }

        //agar current value low se choti hai to left part ignore kro aur right me search kro
        else if(root->val<low){
            sum += rangeSumBST(root->right, low, high);
        }
        //agar current value high se badi hai to right part ignore kro aur left me search kro
        else{
            sum += rangeSumBST(root->left, low, high);
        }

        return sum;
    
    }
};