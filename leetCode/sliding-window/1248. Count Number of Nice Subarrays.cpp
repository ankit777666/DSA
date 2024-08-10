class Solution {
public:
    int util(vector<int>&nums, int k) {
      int n=nums.size();
      int i=0, j=0;

      int ans=0, count=0;
      while(j<n) {
        if(nums[j]%2!=0)
          count++;

        while(count>k) {
          if(nums[i]%2!=0)
            count--;
          i++;
        }
        ans+=j-i+1;
        j++;
      }
      return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
      return util(nums,k)-util(nums,k-1);

    }
};