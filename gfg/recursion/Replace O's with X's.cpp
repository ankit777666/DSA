class Solution{
public:
    void dfs(int i, int j,vector<vector<int>>&visited, vector<vector<char>>&mat) {
        int n=mat.size(), m=mat[0].size();
        visited[i][j]=1;
        if(i+1<n && mat[i+1][j]=='O' && !visited[i+1][j])
            dfs(i+1, j, visited, mat);
        if(i-1>=0 && mat[i-1][j]=='O' && !visited[i-1][j])
            dfs(i-1, j, visited, mat);
        if(j+1<m && mat[i][j+1]=='O'&& !visited[i][j+1])
            dfs(i, j+1, visited, mat);
        if(j-1>=0 && mat[i][j-1]=='O' && !visited[i][j-1])
            dfs(i, j-1, visited, mat);
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>>visited(n, vector<int>(m,0));
        for(int j=0; j<m; j++) {
            if(!visited[0][j] && mat[0][j]=='O') {
                dfs(0,j, visited, mat);
            }
            if(!visited[n-1][j] && mat[n-1][j]=='O') {
                dfs(n-1, j, visited, mat);
            }
        }
        for(int i=0; i<n; i++) {
            if(!visited[i][0] && mat[i][0]=='O') {
                dfs(i,0,visited,mat);
            }
            if(!visited[i][m-1] && mat[i][m-1]=='O') {
                dfs(i,m-1, visited, mat);
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!visited[i][j] && mat[i][j]=='O')
                    mat[i][j]='X';
            }
        }
        return mat;
    }
};