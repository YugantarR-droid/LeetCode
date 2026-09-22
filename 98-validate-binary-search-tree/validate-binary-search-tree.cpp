class Solution {
public:
    long long findMin(TreeNode* root) {
        if(root == NULL)
            return LLONG_MAX;

        long long leftMin = findMin(root->left);
        long long rightMin = findMin(root->right);

        return min((long long)root->val, min(leftMin, rightMin));
    }

    long long findMax(TreeNode* root) {
        if(root == NULL)
            return LLONG_MIN;

        long long leftMax = findMax(root->left);
        long long rightMax = findMax(root->right);

        return max((long long)root->val, max(leftMax, rightMax));
    }

    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;

        long long leftTree = findMax(root->left);
        long long rightTree = findMin(root->right);

        if(root->val <= leftTree || root->val >= rightTree)
            return false;

        bool leftAns = isValidBST(root->left);
        bool rightAns = isValidBST(root->right);

        return leftAns && rightAns;
    }
};