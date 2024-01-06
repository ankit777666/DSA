class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int ans=0;
        for(int i=2; i<n; i++) {
            int last=nums[i];
            int low=0, high=i-1;
            while(low<high) {
                if(nums[high]+nums[low]>last) {
                    ans+=high-low;
                    high--;
                }
                else {
                    low++;
                }
            }
        }
        return ans;
    }
};