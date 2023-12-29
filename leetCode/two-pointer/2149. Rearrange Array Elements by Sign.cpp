class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size(), i = 0 , j = 0;

        while(i < n && j < n){
            while(i < n && nums[i] < 0){
                i++;
            }
            while(j < n && nums[j] > 0){
                j++;
            }
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);

            i++,j++;
        }
        return ans;
    }
};