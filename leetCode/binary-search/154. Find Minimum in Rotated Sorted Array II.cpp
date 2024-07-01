class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0, high=n-1;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(nums[mid]<nums[high]) {
                high=mid;
            }
            else if(nums[mid]>nums[high]) {
                low=mid+1;
            }
            else {
                high=high-1;
            }
        }
        return nums[low];
    }
};

/**
 * Approach same as search in rotated array -II
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0, high=nums.size()-1;
        int ans=INT_MAX;

        while(low<=high) {
            int mid=low+(high-low)/2;
            if(nums[low]==nums[mid] &&  nums[mid]==nums[high]) {
                ans=min(ans, nums[mid]);
                low=low+1;
                high=high-1;
                continue;
            }
            else if(nums[low]<=nums[mid]) {
                ans=min(ans, nums[low]);
                low=mid+1;
            }
            else {
                ans=min(ans, nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};