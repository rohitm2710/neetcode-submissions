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
int abs_min=-1001;
int abs_max=1001;
    bool dfs(TreeNode* root,int min_val,int max_val){
        if(!root) return true;
        if(root->val<min_val||root->val>max_val){
            return false;
        }
        return dfs(root->left,min_val,root->val-1)&&dfs(root->right,root->val+1,max_val);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return dfs(root,abs_min,abs_max);
    }
};
