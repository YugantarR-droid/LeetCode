/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int getSize(ListNode* head){
        ListNode* temp = head;
        int size = 0;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        return size;
    }
    TreeNode* buildBST(ListNode* &head,int n){
        if(head==NULL)
        return NULL;

        if(n<=0)
        return NULL;

        //left subtree banao
        TreeNode* leftSubTree = buildBST(head,n/2);

        int element = head->val;

        TreeNode* root = new TreeNode(element);

        root->left = leftSubTree;

        head = head->next;

        TreeNode* rightSubTree = buildBST(head,n-n/2-1);

        root->right = rightSubTree;

        return root;

    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
        return NULL;

        int n = getSize(head);

        return buildBST(head,n);

    }
};