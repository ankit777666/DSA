class Solution {
public:
    void util(int index, int k, int n, vector<int>nums, vector<int>&v, vector<vector<int>>&ans) {
        
        if(k==0 && n==0) {
            ans.push_back(v);
            return;
        }
        
        for(int i=index; i<nums.size(); i++) {
            v.push_back(nums[i]);
            util(i+1, k-1,n-nums[i], nums, v, ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums;
        for(int i=1; i<=9; i++) {
            nums.push_back(i);
        }
        
        vector<vector<int>>ans;
        vector<int>v;
        int index=0;
        util(index, k,n, nums,v,ans);
        return ans;
    }
};