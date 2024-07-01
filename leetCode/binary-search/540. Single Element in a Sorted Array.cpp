class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=1, high=nums.size()-2;
        int ans;
        if(nums.size()==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[nums.size()-1]!=nums[nums.size()-2]) return nums[nums.size()-1];
        while(low<=high) {
            int mid = low+(high-low)/2;
            if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1])
                return nums[mid];
            if((mid%2==1 && nums[mid]==nums[mid-1])
            || (mid%2==0 && nums[mid]==nums[mid+1])) {
                low=mid+1;
            }
            else {
                high=mid-1;
            }
            

        }
        return -1;
        
    }
};