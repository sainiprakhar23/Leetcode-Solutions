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
    void insert(TreeNode* root, int& data){
        if(root == nullptr){ 
                root = new TreeNode(data);
                return;
        }
        if(root->val > data){
            if(root->left ==NULL){ 
                root->left = new TreeNode(data); 
                return;
            }
            insert(root->left,data);
        }
        if(root->val < data){
            if(root->right ==NULL){ 
                root->right = new TreeNode(data); 
                return;
            }
            insert(root->right,data);
        } 
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            insert(root,preorder[i]);
        }
        return root;

    }
};