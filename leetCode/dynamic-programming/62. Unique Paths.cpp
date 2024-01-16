class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0; i<m; i++)
            dp[i][0]=1;
        for(int i=0; i<n; i++)
            dp[0][i]=1;
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

//recursion
class Solution {
public:
    int util(int i, int j, int m, int n) {
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0)
            return 0;
        return util(i-1,j,m,n)+util(i,j-1, m,n);
    }
    int uniquePaths(int m, int n) {
        
        int i=m-1, j=n-1;
        return util(i, j, m, n);
    }
};