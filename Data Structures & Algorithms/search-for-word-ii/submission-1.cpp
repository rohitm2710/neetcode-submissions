class Solution {
private:
    class TrieNode{
    public:
        bool isEnd;
        TrieNode* children[26];
        TrieNode(){
            isEnd=false;
            for(int i=0;i<26;i++){
                children[i]=nullptr;
            }
        }
    };

    void make_Trie(vector<string> words,TrieNode* root){
        for(string word : words){
            TrieNode* curr=root;
            for(char c : word){
                if(!curr->children[c-'a']){
                    curr->children[c-'a']=new TrieNode();
                }
                curr=curr->children[c-'a'];
            }
            curr->isEnd=true;
        }
    }

    vector<string> res;

    void dfs(vector<vector<char>>& board,TrieNode* root,int i,int j,string& curr){
        
        if(i<0||j<0||i==board.size()||j==board[0].size()){
            return;
        }
        char val=board[i][j];
        if(val=='#'||!root->children[val-'a']) return;
        curr.push_back(val);
        TrieNode* newNode=root->children[val-'a'];
        if(newNode->isEnd){
            res.push_back(curr);
            newNode->isEnd=false;
        }
        board[i][j]='#';
        dfs(board,root->children[val-'a'],i+1,j,curr);
        dfs(board,root->children[val-'a'],i,j+1,curr);
        dfs(board,root->children[val-'a'],i-1,j,curr);
        dfs(board,root->children[val-'a'],i,j-1,curr);
        curr.pop_back();
        board[i][j]=val;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root=new TrieNode();
        make_Trie(words,root);
        string curr;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(board,root,i,j,curr);
            }
        }
        return res;
    }
};
