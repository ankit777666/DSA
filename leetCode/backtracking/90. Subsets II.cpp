class Solution {
public:
    void util(int index,vector<int>&nums,vector<int>&v,vector<vector<int>>&ans) {    
            ans.push_back(v);
            for(int i=index; i<nums.size(); i++) {
                if(i>index && nums[i]==nums[i-1])
                    continue;
                v.push_back(nums[i]);
                util(i+1, nums,v,ans);
                v.pop_back();
            }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        int index=0;
        sort(nums.begin(), nums.end());
        util(index, nums, v, ans);
        return ans;
    }
};