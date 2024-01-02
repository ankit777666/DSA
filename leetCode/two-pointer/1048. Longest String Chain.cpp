class Solution {
public:
    
    bool isPossible(string &a, string &b) {
        if(a.size()!=b.size()+1)
            return false;
        int i=0, j=0;
        while(i<a.size()) {
            if(a[i]==b[j]) {
                i++;
                j++;
            }
            else {
                i++;
            }
        }
        if(i==a.size() && j==b.size())
            return true;    
        return false;
    }
    static bool comp(string &a, string &b) {
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        vector<int>dp(n,1);
        int ans=1;

        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(isPossible(words[i],words[j]) && dp[i]<dp[j]+1) {
                    dp[i]=dp[j]+1;
                }
                

            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};