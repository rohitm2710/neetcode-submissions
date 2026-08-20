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
    int count=0;
    void dfs(TreeNode* root,int last_max){
        if(!root) return;
        if(root->val>=last_max) count++;
        dfs(root->left,max(last_max,root->val));
        dfs(root->right,max(last_max,root->val));
    }
public:
    int goodNodes(TreeNode* root) {
        dfs(root,INT_MIN);
        return count;
    }
};
