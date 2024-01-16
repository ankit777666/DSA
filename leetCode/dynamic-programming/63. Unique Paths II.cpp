class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        vector<vector<int>>dp(m, vector<int>(n,0));

        for(int i=0; i<m; i++) {
            if(obstacleGrid[i][0]!=1) {
                dp[i][0]=1;
            }
            else
                break;

        }
        for(int i=0; i<n; i++) {
            if(obstacleGrid[0][i]!=1) {
                dp[0][i]=1;
            }
            else
                break;
        }
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(obstacleGrid[i][j]!=1)
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                else
                    continue;
            }
        }
        return dp[m-1][n-1];
    }
};

//recursion
class Solution {
public:
    int util(int i, int j, int m, int n,vector<vector<int>>& obstacleGrid) {
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0 || obstacleGrid[i][j]==1)
            return 0;
        return util(i-1,j,m,n,obstacleGrid)+util(i,j-1,m,n,obstacleGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        return util(m-1, n-1, m,n,obstacleGrid);
    }
};