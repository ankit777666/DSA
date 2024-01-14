// tablulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,0);
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        dp[0]=0, dp[1]=nums[0], dp[2]=max(nums[0], nums[1]);

        for(int i=2; i<=n; i++) {
             dp[i] = max(nums[i-1]+dp[i-2], dp[i-1]);
        }
        return dp[n];
    }
};

//recursion
class Solution {
public:
    int util(int index, vector<int>&nums) {
        if(index==0)
            return nums[0];
        if(index<0)
            return 0;
        return max(nums[index]+util(index-2, nums), util(index-1,nums));
    }
    int rob(vector<int>& nums) {
    int n=nums.size();
    int index=n-1;
    return util(index, nums);   
    }   
};

//memoization
class Solution {
public:
    int util(int index, vector<int>&nums, vector<int>&dp) {
        if(index==0)
            return nums[0];
        if(index<0)
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        dp[index]=max(nums[index]+util(index-2,nums,dp), util(index-1, nums,dp));
        return dp[index];
    }
    int rob(vector<int>& nums) {

    int n=nums.size();
    int index=n-1;
    vector<int>dp(n,-1);
    return util(index, nums, dp);   
    }
    
};