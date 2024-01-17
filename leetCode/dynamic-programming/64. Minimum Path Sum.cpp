class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0; i<m; i++) {
            if(i==0)
                dp[i][0]=grid[i][0];
            else
                dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int i=0; i<n; i++) {
            if(i==0)
                dp[0][i]=grid[0][i];
            else
                dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
        
            
    }
};

//recursion

class Solution {
public:
    int util(int i, int j, int m, int n,vector<vector<int>>& grid) {
        if(i==0 && j==0)
            return grid[i][j];
        if(i<0 || j<0)
            return INT_MAX;
        int down=util(i-1,j,m,n,grid);
        int right=util(i,j-1,m,n,grid);
        return min(down, right)+grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int i=m-1, j=n-1;
        return util(i,j,m,n, grid);
            
    }
};
//memoization
class Solution {
public:
    int util(int i, int j, int m, int n,vector<vector<int>>& grid, vector<vector<int>>&dp) {
        if(i==0 && j==0)
            return grid[i][j];
        if(i<0 || j<0)
            return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int down=util(i-1,j,m,n,grid,dp);
        int right=util(i,j-1,m,n,grid,dp);
        return dp[i][j]=min(down, right)+grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int i=m-1, j=n-1;
        return util(i,j,m,n, grid,dp);
            
    }
};