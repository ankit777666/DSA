class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0, right=-1;
        int minVal=INT_MAX, maxVal=INT_MIN;
        for(int i=0; i<n; i++) {
            maxVal=max(maxVal,nums[i]);
            if(nums[i]<maxVal)
                right=i;
        }
        for(int j=n-1; j>=0; j--) {
            minVal=min(minVal,nums[j]);
            if(nums[j]>minVal)
                left=j;
        }
        return right-left+1;
    }
};