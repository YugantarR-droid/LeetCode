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
    int findMax(TreeNode* root) {
    while(root->right != NULL) {
        root = root->right;
    }

    return root->val;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        return NULL;

        if(root->val==key){
            //4 cases

            //it is a lead node
            if(root->left == NULL && root->right==NULL){
                TreeNode* temp = root;
                delete temp;
                return NULL;
            }
            
            //it is root with left child;
            if(root->left!=NULL && root->right==NULL){
                TreeNode* temp = root;
                TreeNode* child = root->left;
                delete temp;
                return child;
            }
            //it is root with right child;
            if(root->left==NULL && root->right!=NULL){
                TreeNode* temp = root;
                TreeNode* child = root->right;
                delete temp;
                return child;
            }
            //root with both child
            if(root->left!=NULL && root->right!=NULL){
                int maxElement = findMax(root->left);
                root->val=maxElement;
                root->left = deleteNode(root->left,maxElement);
                return root;
            }
        }
        else if(key>root->val){
            root->right = deleteNode(root->right,key);
        }
        else{
            root->left = deleteNode(root->left,key);
        }
        return root;
    }
};