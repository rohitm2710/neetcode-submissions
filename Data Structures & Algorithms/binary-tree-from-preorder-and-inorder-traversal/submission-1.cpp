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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int Pstart,int Pend,int Istart,int Iend){
        if(Pstart>Pend||Istart>Iend){
            return nullptr;
        }
        int num=preorder[Pstart];
        auto midIter=std::find(inorder.begin()+Istart,inorder.begin()+Iend+1,num);
        int mid=midIter-inorder.begin();
        TreeNode* root = new TreeNode(num);
        int leftLen = mid - Istart;
        root->left = build(preorder, inorder, Pstart + 1, Pstart + leftLen, Istart, mid - 1);

        root->right = build(preorder, inorder, Pstart + leftLen + 1, Pend, mid + 1, Iend);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()||inorder.empty()){
            return nullptr;
        }
        return build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};
