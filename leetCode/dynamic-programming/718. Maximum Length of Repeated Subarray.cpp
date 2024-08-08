class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
      int n1=nums1.size(), n2=nums2.size();
      if(n1<n2) return findLength(nums2,nums1);
      vector<int>dp(n1+1,0);
      vector<int>dp1(n1+1,0);
      int ans=0;

      for(int i=1; i<=n1; i++) {
        for(int j=1; j<=n2; j++) {
          if(nums1[i-1]==nums2[j-1])
            dp[j]=dp1[j-1]+1;
          else
            dp[j]=0;
          ans=max(ans,dp[j]);
        }
        dp.swap(dp1);
      }
      return ans;
    }
};