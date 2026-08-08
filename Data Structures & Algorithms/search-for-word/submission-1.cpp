class Solution {
private:
    bool dfs(vector<vector<char>>& board, string& word, int i,int j,int curr){
        if(curr==word.size()) return true;
        if(i==board.size()||j==board[0].size()||i<0||j<0){
            return false;
        }
        if(word[curr]!=board[i][j]){
            return false;
        }
        char temp=board[i][j];
        board[i][j]='#';
        bool res= dfs(board,word,i+1,j,curr+1)||dfs(board,word,i,j+1,curr+1)||dfs(board,word,i-1,j,curr+1)||dfs(board,word,i,j-1,curr+1);
        board[i][j]=temp;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
};
