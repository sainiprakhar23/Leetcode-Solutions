class Solution {
public:
    void swap (int& first, int& second){
        int temp = first;
        first=second;
        second=temp;
    }
    void check(TreeNode*& root, TreeNode*& prev,TreeNode*& first,TreeNode*& second){
        if(root==NULL) return;
        check(root->left,prev,first,second);
        if(prev && prev->val >= root->val){
            if(first == nullptr)first=prev;
            second=root;
        }
        prev=root;
        check(root->right,prev,first,second); 
    }
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* prev = NULL;
        check(root,prev,first,second);
        
        if(first!=NULL && second!=NULL){
            swap(first->val,second->val);
        }
    }
};