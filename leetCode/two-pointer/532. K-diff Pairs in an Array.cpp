class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int ans=0;
        int i=0, j=1;
        while(i<n && j<n) {
            if(i==j || nums[j]-nums[i]<k) {
                j++;
            }
            else {
                if(nums[j]-nums[i]==k) {
                    ans++;
                    j++;
                    while(j<n && nums[j]==nums[j-1])
                        j++;
                }
                i++;
                while(i<j && nums[i]==nums[i-1])
                    i++;
            }
        }
        return ans;
    }
};