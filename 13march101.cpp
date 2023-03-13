class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()) {
            TreeNode* r1=q.front(); q.pop();
            TreeNode* r2=q.front(); q.pop();
            if(r1==NULL and r2==NULL) continue;
            if(r1==NULL or r2==NULL) return 0;
            if(r1->val!=r2->val) return 0;
            q.push(r1->left); q.push(r2->right);
            q.push(r1->right); q.push(r2->left);
        }
        return 1;
    }
};
