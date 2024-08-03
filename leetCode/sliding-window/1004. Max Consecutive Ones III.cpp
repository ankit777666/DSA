//unoptimized - beats 5%
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0, j=0;
        unordered_map<int,int> umap;
        int maxLen=INT_MIN;

        while(j<n) {
          umap[nums[j]]++;
          while(umap[0]>k) {
            if(nums[i]==0)
              umap[0]--;
            i++;
          }
          maxLen=max(maxLen, j-i+1);
          j++;
        }
        return maxLen;
    }
};

// optimized - beats 86%
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0, j=0;
        int zeroCount=0;
        int maxLen=INT_MIN;

        while(j<n) {
          if(nums[j]==0)
            zeroCount++;
          while(zeroCount>k) {
            if(nums[i]==0)
              zeroCount--;
            i++;
          }
          maxLen=max(maxLen, j-i+1);
          j++;
        }
        return maxLen;
    }
};