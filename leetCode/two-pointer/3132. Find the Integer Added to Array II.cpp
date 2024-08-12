class Solution {
public:
    bool util(vector<int>&nums1, vector<int>&nums2, int diff){
      int count=0, i=0, j=0;
      while(i<nums1.size() && j<nums2.size()) {
        if(nums1[i]+diff!=nums2[j])
          count++;
        else
          j++;
        i++;
      }
      if(count>2)
        return 0;
      return 1;
    }

    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
      sort(nums1.begin(), nums1.end());
      sort(nums2.begin(), nums2.end());

      int ans=INT_MAX;
      for(int i=0; i<nums1.size(); i++) {
        int diff=nums2[0]-nums1[i];
        if(util(nums1, nums2, diff))
          ans=min(ans, diff);
      }
      return ans;    
    }
};