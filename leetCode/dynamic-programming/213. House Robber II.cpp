class Solution {
public:
    int util(vector<int>& nums) {
        int n=nums.size();
        int prev1=nums[0], prev2=0;
        

        for(int i=1; i<n; i++) {
            int take=nums[i];
            if(i>1)
                take+=prev2;
            int noTake=prev1;
            int curr=max(take, noTake);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>arr1, arr2;
        for(int i=0; i<n; i++) {
            if(i!=0)
                arr1.push_back(nums[i]);
            if(i!=n-1)
                arr2.push_back(nums[i]);

        }
        int ans1=util(arr1), ans2=util(arr2);
        return max(ans1, ans2);
    }
};