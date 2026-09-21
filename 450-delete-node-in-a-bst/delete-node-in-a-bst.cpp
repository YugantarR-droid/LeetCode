/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int getMax(TreeNode* root) {
        while (root->right != NULL) {
            root = root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;

        if (root->val == key) {
            // 4 cases
            // 1) leaf node
            if (root->left == NULL && root->right == NULL) {
                TreeNode* temp = root;
                delete temp;
                return NULL;
            }

            // 2) has left child
            if (root->left != NULL && root->right == NULL) {
                TreeNode* temp = root;
                TreeNode* child = root->left;
                delete temp;
                return child;
            }
            // 3) has right child
            if (root->left == NULL && root->right != NULL) {
                TreeNode* temp = root;
                TreeNode* child = root->right;
                delete temp;
                return child;
            }
            //4) has both childs
            if (root->left != NULL && root->right != NULL) {
                // get max element in left subtree
                int element = getMax(root->left);
                root->val = element;
                root->left = deleteNode(root->left, element);
            }
        } else if(key<root->val){
            // left 
           root->left = deleteNode(root->left, key);
        } else{
            //right
           root->right = deleteNode(root->right, key);
        }
        return root;
    }
};