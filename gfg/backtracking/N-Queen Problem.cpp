class Solution{
public:
    bool isSafe(int row, int col, vector<string>&board, int n) {
        int row1=row, col1=col;
        while(row>=0 && col>=0) {
            if(board[row][col]=='1')
                return false;
            row--; col--;
        }
        row=row1; col=col1;
        while(col>=0) {
            if(board[row][col]=='1')
                return false;
            col--;
        }
        row=row1; col=col1;
        while(row<n && col>=0) {
            if(board[row][col]=='1')
                return false;
            row++; col--;
        }
        return true;
    }
    void solve(int col, vector<string>&board, vector<vector<int>>&ans, int n) {
        if(col==n) {
            vector<int>temp;
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(board[j][i]=='1')
                        temp.push_back(j+1);
                }
            }
            ans.push_back(temp);
            return;
        }
        for(int row=0; row<n; row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col]='1';
                solve(col+1, board, ans, n);
                board[row][col]='0';
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>ans;
        // vector<vector<int>>board(n, vector<int>(n,0));
        vector<string>board(n);
        string s(n,'0');
        for(int i=0; i<n; i++) 
            board[i]=s;
        solve(0, board, ans, n);
        return ans;
    }
};