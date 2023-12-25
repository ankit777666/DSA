class Solution {
public:
    bool existUtil(int i, int j,int index,vector<vector<char>>&board,vector<vector<bool>>&visited,string &word) {
        if(index==word.size()-1)
            return true;
        visited[i][j]=true;

        if(i+1<board.size() && !visited[i+1][j] && board[i+1][j]==word[index+1] && existUtil(i+1,j, index+1,board,visited,word))
            return true;
        if(i-1>=0 && !visited[i-1][j] && board[i-1][j]==word[index+1] && existUtil(i-1,j, index+1,board,visited,word))
            return true;
        if(j+1<board[0].size() && !visited[i][j+1] && board[i][j+1]==word[index+1] && existUtil(i,j+1, index+1,board,visited,word))
            return true;
        if(j-1>=0 && !visited[i][j-1] && board[i][j-1]==word[index+1] && existUtil(i,j-1, index+1,board,visited,word))
            return true;

        visited[i][j]=false;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int index=0;
        int n=board.size(), m=board[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m,false));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j]==word[0] && existUtil(i,j, index,board,visited,word)) {
                    return true;
                }
            }
        }
        return false;
        
        
    }
};

//Another approach

class Solution {
public:
    bool existUtil(int i, int j,int index,vector<vector<char>>&board,string &word) {
        if(index==word.size()-1)
            return true;
        // visited[i][j]=true;
        char temp=board[i][j];
        board[i][j]='_';
        if(i+1<board.size() && board[i+1][j]==word[index+1] && existUtil(i+1,j, index+1,board,word))
            return true;
        if(i-1>=0 && board[i-1][j]==word[index+1] && existUtil(i-1,j, index+1,board,word))
            return true;
        if(j+1<board[0].size() && board[i][j+1]==word[index+1] && existUtil(i,j+1, index+1,board,word))
            return true;
        if(j-1>=0 && board[i][j-1]==word[index+1] && existUtil(i,j-1, index+1,board,word))
            return true;
        board[i][j]=temp;
        // visited[i][j]=false;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int index=0;
        int n=board.size(), m=board[0].size();
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j]==word[0] && existUtil(i,j, index,board,word)) {
                    return true;
                }
            }
        }
        return false;
        
        
    }
};