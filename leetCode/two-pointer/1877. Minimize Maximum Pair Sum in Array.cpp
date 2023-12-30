class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        if(n==2)
            return nums[0]+nums[1];
        sort(nums.begin(), nums.end());
        int low=0, high=n-1;
        int maxSum=INT_MIN;
        while(low<high) {
            int sum=nums[low]+nums[high];
            maxSum=max(maxSum, sum);
            low++;high--;
        }
        return maxSum;
        
    }
};