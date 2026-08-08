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

class Codec {

private:

    void serializeDFS(TreeNode* root,stringstream& ss){
        if(!root){
            ss << "N ";
            return;
        }

        ss<<to_string(root->val)<<" ";
        serializeDFS(root->left,ss);
        serializeDFS(root->right,ss);
    }

    TreeNode* deserializeDFS(stringstream& ss){
        string val;
        if(!(ss >> val)||val=="N"){
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(val));
        root->left=deserializeDFS(ss);
        root->right=deserializeDFS(ss);

        return root;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        serializeDFS(root,ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeDFS(ss);
    }
};
