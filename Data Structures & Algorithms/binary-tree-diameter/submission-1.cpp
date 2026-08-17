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
    int dfs(TreeNode* node,int& max_diameter){
        if(!node) return 0;
        int left_depth=dfs(node->left,max_diameter);
        int right_depth=dfs(node->right,max_diameter);
        max_diameter=max(max_diameter,left_depth+right_depth);
        return 1+max(left_depth,right_depth);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter=0;
        dfs(root,max_diameter);
        return max_diameter;
    }
};
