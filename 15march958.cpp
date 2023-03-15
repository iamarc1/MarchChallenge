class Solution {
public:
    int TotalNode(TreeNode *root){
        if(root==NULL) return 0;
        return 1 + TotalNode(root->left) + TotalNode(root->right);
    }
    bool isCompleteTree(TreeNode* root) {
        int totalEle = TotalNode(root);
        int count = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()==false){
           
            TreeNode* curr = q.front();
            if(curr==NULL){
                break;
            }
            q.pop();
            count++;
            q.push(curr->left);
            q.push(curr->right);
        }
        
        if(count<totalEle) return false;
        return true;
    }
};
