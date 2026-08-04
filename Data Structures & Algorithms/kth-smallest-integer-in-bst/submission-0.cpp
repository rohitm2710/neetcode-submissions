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
    int n;
    int res;
    int curr=0;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        curr++;
        if(curr==n){
            res=root->val;
            return;
        }
        dfs(root->right);
       
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        n=k;
        dfs(root);
        return res;
    }
};
