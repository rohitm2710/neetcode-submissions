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
    pair<bool,int> balance(TreeNode* root,int depth){
        if(!root) return {true,0};
        auto left=balance(root->left,depth);
        auto right=balance(root->right,depth);
        bool balanced=(left.first&&right.first&&(abs(left.second-right.second)<=1));
        return {balanced,1+max(left.second,right.second)};
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return balance(root,0).first;
    }
};
