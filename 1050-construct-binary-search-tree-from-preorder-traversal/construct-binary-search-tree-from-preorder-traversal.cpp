class Solution {
public:
    // void insert(TreeNode* root, int& data){
    //     if(root == nullptr){ 
    //             root = new TreeNode(data);
    //             return;
    //     }
    //     if(root->val > data){
    //         if(root->left ==NULL){ 
    //             root->left = new TreeNode(data); 
    //             return;
    //         }
    //         insert(root->left,data);
    //     }
    //     if(root->val < data){
    //         if(root->right ==NULL){ 
    //             root->right = new TreeNode(data); 
    //             return;
    //         }
    //         insert(root->right,data);
    //     } 
    // }
    // TreeNode* bstFromPreorder(vector<int>& preorder) {
    //     TreeNode* root = new TreeNode(preorder[0]);
    //     for(int i=1;i<preorder.size();i++){
    //         insert(root,preorder[i]);
    //     }
    //     return root;

    // }




    /*ITERATION*/
    // TreeNode* insert(TreeNode* root, int data) {
    //     TreeNode* node = new TreeNode(data);

    //     if (root == NULL)
    //         return node;

    //     TreeNode* curr = root;

    //     while (true) {
    //         if (data < curr->val) {
    //             if (curr->left == NULL) {
    //                 curr->left = node;
    //                 break;
    //             }
    //             curr = curr->left;
    //         }
    //         else {
    //             if (curr->right == NULL) {
    //                 curr->right = node;
    //                 break;
    //             }
    //             curr = curr->right;
    //         }
    //     }

    //     return root;
    // }

    TreeNode* insert2(TreeNode* root, int data) {
        TreeNode* node = new TreeNode(data);

        if (root == NULL)
            return node;

        TreeNode* curr = root;
        TreeNode* prev = NULL;

        while (curr != NULL) {
            prev = curr;

            if (data < curr->val)
                curr = curr->left;
            else
                curr = curr->right;
        }

        // prev is the parent where the new node should be attached
        if (data < prev->val)
            prev->left = node;
        else
            prev->right = node;

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;

        // iteration 1 method
        // for (int x : preorder) {
        //     root = insert(root, x);
        // }
        //iteration 2 method
        for (int x : preorder) {
            root = insert2(root, x);
        }

        return root;
    }
};