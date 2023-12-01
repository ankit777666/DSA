class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    // code here
	    long long int mod=1e9+7;
        int dp[n+1];
        dp[1]=2;
        dp[2]=3;
        for(int i=3;i<=n;i++)
            dp[i]=(dp[i-1]+dp[i-2])%mod;
       return dp[n];
	}
};