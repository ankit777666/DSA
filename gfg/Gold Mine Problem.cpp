class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int ans=INT_MIN;
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
            dp[i][0]=M[i][0];
        
        
        for(int j=1; j<m; j++) {
            for(int i=0; i<n; i++) {
                int path1=INT_MIN, path2=INT_MIN, path3=INT_MIN;
                if(j-1>=0) {
                    path1=M[i][j]+dp[i][j-1];
                }
                if(i-1>=0 && j-1>=0) {
                    path2=M[i][j]+dp[i-1][j-1];
                }
                if(i+1<n && j-1>=0) {
                    path3=M[i][j]+dp[i+1][j-1];
                }
                dp[i][j]=max(path1,max(path2, path3));
            }
        }
        for(int i=0; i<n; i++) {
            ans=max(ans, dp[i][m-1]);
        }
        return ans;
    }
};