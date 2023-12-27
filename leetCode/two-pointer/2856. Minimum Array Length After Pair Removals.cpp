class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        unordered_map<int, int>umap;
        for(auto i: nums)
            umap[i]++;
        int maxE = INT_MIN;
        for(auto i: umap)
            maxE=max(maxE, i.second);
        if(maxE<=nums.size()/2) {
            if(nums.size()%2==0)
                return 0;
            else
                return 1;
        }
        return 2*maxE-nums.size();
    }
};