class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int>umap;
        int len=0, ans=0;
        int i=0, j=0;
        while(j<n) {
            umap[nums[j]]++;
            while(umap[nums[j]]>k) {
                umap[nums[i]]--;
                i++;
                
            }
            j++;
            len=j-i;
            ans=max(ans,len);
            
        }
        return ans;
    }
};