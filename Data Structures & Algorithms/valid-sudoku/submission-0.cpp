class Solution {
private:
    vector<vector<int>> rows{9,vector<int>(10,0)};
    vector<vector<int>> columns{9,vector<int>(10,0)};
    vector<vector<int>> boxes{9,vector<int>(10,0)};
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int val=board[i][j]-'0';
                    if(rows[i][val]||columns[j][val]||boxes[((i/3)*3)+(j/3)][val]){
                        return false;
                    }
                    else{
                        rows[i][val]=1;
                        columns[j][val]=1;
                        boxes[((i/3)*3)+(j/3)][val]=1;
                    }
                }
            }
        }
        return true;
    }
};
