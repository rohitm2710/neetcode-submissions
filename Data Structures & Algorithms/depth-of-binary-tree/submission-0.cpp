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
    int max_len=1;
    int curr=1;
    void traversal(TreeNode* root){
        if(!root) return;
        curr++;
        traversal(root->left);
        traversal(root->right);
        curr--;
        max_len=max(max_len,curr);
    }
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        traversal(root);
        return max_len;
    }
};
