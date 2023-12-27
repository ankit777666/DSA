class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n=nums.size(); int ans=0;
        sort(nums.begin(), nums.end());
        int i=0, j=n/2;
        while(i<n/2 && j<n) {
            if(2*nums[i]<=nums[j]) {
                i++;j++;
                ans+=2;
            }
            else {
                j++;
            }
        }
        return ans;

    }
};