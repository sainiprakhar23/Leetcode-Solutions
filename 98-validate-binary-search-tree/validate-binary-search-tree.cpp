class Solution {
public:
    // Inorder traversal of BST is sorted
    // T.C = O(n) S.C = O(n)
    // void inorder(TreeNode* root, vector<int>& v) {
    //     if (root == NULL) return;
    //     inorder(root->left, v);
    //     v.push_back(root->val);
    //     inorder(root->right, v);
    // }
    // bool isValidBST(TreeNode* root) {
    //     vector<int> v;
    //     inorder(root, v);
    //     for (int i = 1; i < v.size(); i++) {
    //         if (v[i] <= v[i - 1]) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // S.C = O(1)
    void check(TreeNode*& root, TreeNode*& prev, bool& flag){
        if(root==NULL) return;
        // inorder
        check(root->left,prev,flag);
        if(prev!=NULL){
            if(root->val <= prev->val){
                flag=false;
                return;
            }
        }
        prev=root;
        check(root->right,prev,flag); 
    }
     bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        bool flag = true;
        check(root,prev,flag);
        return flag;
    }
};
   
