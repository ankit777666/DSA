class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod=1e9+7;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<int>p2(nums.size());
        p2[0] = 1; int ans=0;
        for(int i = 1; i < nums.size(); i++) {
            p2[i] = (p2[i-1] * 2)%mod;
        }
        int i=0, j=n-1;
        while(i<=j) {
            if(nums[i]+nums[j]<=target) {
                ans=(ans+p2[j-i])%mod;
                i++;
            }
            else {
                j--;
            }
        }
        return ans;
    }
};