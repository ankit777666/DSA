class Solution {
public:
    bool dfs(int i, int j, int index, vector<vector<char>>& board,string word) {
        if(index==word.size()-1) {
            return true;
        }
        int n=board.size(), m=board[0].size();
        char temp=board[i][j];
        board[i][j]='_';
        if(i+1<n && board[i+1][j]==word[index+1] && dfs(i+1,j, index+1,board,word))
            return true;
        if(i-1>=0 && board[i-1][j]==word[index+1] && dfs(i-1,j, index+1,board,word))
            return true;
        if(j+1<m && board[i][j+1]==word[index+1] && dfs(i,j+1, index+1,board,word))
            return true;
        if(j-1>=0 && board[i][j-1]==word[index+1] && dfs(i,j-1, index+1,board,word))
            return true;
        board[i][j]=temp;
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int index=0;
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j]==word[index] && dfs(i,j, index, board, word))
                    return true;
            }
        }
        return false;
    }
};