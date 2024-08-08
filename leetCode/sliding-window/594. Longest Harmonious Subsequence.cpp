class Solution {
public:
    int findLHS(vector<int>& nums) {
      int n=nums.size();
      int i=0, j=1;
      sort(nums.begin(), nums.end());

      int maxLen=0;
      while(j<n) {
        if(nums[j]-nums[i]  == 1)
          maxLen=max(maxLen, j-i+1);
        while(nums[j]-nums[i]>1)
          i++;
        j++;
      }
      return maxLen;  
    }
};