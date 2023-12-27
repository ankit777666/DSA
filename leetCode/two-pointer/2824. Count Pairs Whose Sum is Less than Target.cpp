class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        int ans=0;
        while(low<=high) {
            int i=low+1;
            while(i<=high) {
                if(nums[i]+nums[low]<target)
                    ans++;
                i++;
            }
            low++;
        }
        return ans;
    }
};