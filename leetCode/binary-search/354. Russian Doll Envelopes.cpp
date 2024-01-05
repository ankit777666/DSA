class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b) {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(), envelopes.end(),comp);
        vector<int>dp;
        dp.push_back(envelopes[0][1]);

        for(int i=1; i<n; i++) {
            if(envelopes[i][1]>dp.back()) {
                dp.push_back(envelopes[i][1]);
            }
            else {
                int index=lower_bound(dp.begin(),dp.end(), envelopes[i][1])-dp.begin();
                dp[index]=envelopes[i][1];
            }
        }
        return dp.size();
    }
};