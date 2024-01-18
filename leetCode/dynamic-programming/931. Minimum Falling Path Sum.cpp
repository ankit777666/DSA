class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>>dp(row, vector<int>(col,0));
        for(int i=0; i<col; i++) {
            dp[0][i]=matrix[0][i];
        }
        for(int i=1; i<row; i++) {
            for(int j=0; j<col; j++) {
                int d=dp[i-1][j]+matrix[i][j];
                int ld=matrix[i][j];
                int rd=matrix[i][j];
                if(j>0)
                    ld+=dp[i-1][j-1];
                else
                ld=INT_MAX;
                if(j<col-1)
                    rd+=dp[i-1][j+1];
                else
                    rd=INT_MAX;
                dp[i][j]=min(d,min(rd,ld));
                    
            }
        }
        int ans=INT_MAX;
        for(int i=0; i<col; i++) {
            ans=min(ans,dp[row-1][i]);
        }
        return ans;
    }
};