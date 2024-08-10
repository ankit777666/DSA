class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
      int n=nums.size();
      int totalSum=0;
      for(auto ele : nums)
        totalSum+=ele;
      
      int sum=totalSum-x;

      int i=0, j=0;
      int currSum=0;
      int ans=INT_MIN; bool flag=false;
      while(j<n) {
        currSum+=nums[j];
        while(i<=j && currSum>sum) {
          currSum-=nums[i];
          i++;
        }
        if(currSum==sum) {
          flag=true;
          ans=max(ans, j-i+1);
        }
        j++;
          
      }
      return flag ? n-ans : -1;
    }
};