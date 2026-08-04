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
private:
    TreeNode* hold;
    void swapper(TreeNode*& root){
        if(!root) return;
        if(!root->left&&!root->right){
            return;
        }
        hold=root->left;
        root->left=root->right;
        root->right=hold;
        swapper(root->right);
        swapper(root->left);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        swapper(root);
        return root;
    }
};
