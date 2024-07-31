class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum= 0, currSum = 0;
        int l=0, r=0;
        set<int>s;

        while(r<nums.size()) {
          while(s.count(nums[r]) || s.size()==k) {
            currSum-=nums[l];
            s.erase(nums[l]);
            l++;

          }
          currSum+=nums[r];
          s.insert(nums[r]);

          if(s.size() == k)
            maxSum = max(maxSum, currSum);
          r++;
        }
        return maxSum;
    }
};