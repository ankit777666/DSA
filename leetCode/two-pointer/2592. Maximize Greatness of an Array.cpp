class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        int i=0, j=0, n=nums.size();
        while(j<n) {
            if(nums[i]>=nums[j]) {
                j++;
            }
            else if(nums[i]<nums[j]) {
                ans++;
                i++;
                j++;
            }
        }
        return ans;

    }
};