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
    bool equals=true;
    void traversal(TreeNode*& p,TreeNode*& q){
        if(!equals||(!p&&!q)) return;
        if(p&&q&&p->val!=q->val){
            equals=false;
            return;
        }
        if((!p&&q)||(p&&!q)){
            equals=false;
            return;
        }
        traversal(p->left,q->left);
        traversal(p->right,q->right);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q) return true;
        traversal(p,q);
        return equals;
    }
};
