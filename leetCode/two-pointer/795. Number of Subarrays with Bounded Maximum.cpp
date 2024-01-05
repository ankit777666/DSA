class Solution {
public:
    int util(vector<int>&nums, int val) {
        int ans=0, count=0;
        for(int ele: nums) {
            if(ele<=val) {
                count++;
            }
            else
                count=0;
            ans+=count;
        }
        return ans;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return util(nums, right)-util(nums, left-1);
    }
};