class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      int n=nums.size();
      int index1=0, index2=0;

      int j=0, sum1=0,sum2=0, ans=0;

      while(j<n) {
        sum1+=nums[j];
        sum2+=nums[j];

        while(index1<=j && sum1>goal) {
          sum1-=nums[index1];
          index1++;
        }
        while(index2<=j && sum2>=goal) {
          sum2-=nums[index2];
          index2++;
        }
        ans+=index2-index1;
        j++;
      }
      return ans;

    }
};