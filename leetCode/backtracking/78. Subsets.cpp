class Solution {
public:
    void util(int index,vector<int>&nums,vector<int>&v,vector<vector<int>>&ans) {
        if(index>=nums.size()) {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[index]);
        util(index+1, nums,v,ans);
        v.pop_back();
        util(index+1, nums,v, ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        int index=0;
        util(index, nums, v, ans);
        return ans;
    }
};