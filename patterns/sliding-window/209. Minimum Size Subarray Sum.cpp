class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX, currLen = 0;
        int sum = 0;
        int i=0, j=0;

        while(j<nums.size()) {
            sum+=nums[j];
            while(sum>=target) {
                currLen = j-i+1;
                minLen = min(minLen, currLen);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};