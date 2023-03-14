class Solution {
public:
    int total=0;
    void dfs(TreeNode* curr,int value){
        if(!curr) return;

        if(!curr->left && !curr->right){
            total+=curr->val;
            total+=value*10;
            return;
        }

        dfs(curr->left,(value*10)+curr->val);
        dfs(curr->right,(value*10)+curr->val);

    }
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return total;
    }
};
