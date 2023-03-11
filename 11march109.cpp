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
    int listCount(ListNode* head) {
        ListNode *curr = head;
        int c = 0;
        
        while(curr) {
            ++c;
            curr = curr->next;
        }
        return c;
    }
    
    // TC: O(n)
    // Create the tree in inorder manner.
    TreeNode* linearSolution(ListNode*& head, int n) {
        // base case: when 0 or 1 node
        if(n == 0)
            return nullptr;
        
        TreeNode *left = linearSolution(head, n/2);
        
        // create the root node
        TreeNode *root = new TreeNode(head->val);
        // go to the next node in list, so that
        // it will middle node in its previous call
        head = head->next;
        root->left = left;
        
        root->right = linearSolution(head, n - n/2 - 1);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int n_nodes = listCount(head);
        return linearSolution(head, n_nodes);
    }
};
