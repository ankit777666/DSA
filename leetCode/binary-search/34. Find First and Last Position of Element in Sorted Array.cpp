class Solution {
public:
    int findLower(vector<int>&nums, int target) {
        int n=nums.size();
        int ans=-1;
        int low=0,high=n-1;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(nums[mid]==target) {
                ans=mid;
                high=mid-1;

            }
            else if(nums[mid]>target) {
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
    int findHigher(vector<int>&nums, int target) {
        int n=nums.size();
        int ans=-1;
        int low=0,high=n-1;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(nums[mid]==target) {
                ans=mid;
                low=mid+1;

            }
            else if(nums[mid]>target) {
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=findLower(nums, target);
        if(low==-1)
            return {-1,-1};
        int high=findHigher(nums, target); 
        return {low,high};
    }
};