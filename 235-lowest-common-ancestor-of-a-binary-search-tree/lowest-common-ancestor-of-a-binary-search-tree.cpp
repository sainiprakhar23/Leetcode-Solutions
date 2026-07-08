class Solution {
public:
    // TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
    //     if(root->val == p->val || root->val ==q->val) return root;
    //     else if(root-> val > p->val && root->val < q->val) return root;
    //     else if(root-> val < p->val && root->val > q->val) return root;
    //     else if(root-> val < p->val && root->val < q->val) return lca(root->right, p, q);
    //     else return lca(root->left, p, q);
    // }
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     return lca(root,p,q);
        
    // }


    // iteration
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root!=NULL){
            if(p->val < root->val  && q->val < root->val){
                root=root->left;
            } 
            else if(p->val > root->val  && q->val > root->val){
                root=root->right;
            }
            else{
                return root;
            }
        }
        return NULL;
    }
};