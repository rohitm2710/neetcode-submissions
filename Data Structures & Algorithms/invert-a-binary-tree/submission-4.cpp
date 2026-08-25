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
void swap(TreeNode*& a,TreeNode*& b){
    auto* c= a;
    a=b;
    b=c;
}
void inverter(TreeNode* root){
    if(!root) return;
    swap(root->left,root->right);
    inverter(root->left);
    inverter(root->right);
}
public:
    TreeNode* invertTree(TreeNode* root) {
        inverter(root);
        return root;
    }
};
