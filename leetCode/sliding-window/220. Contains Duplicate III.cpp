class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
      int n=nums.size();
      int i=0, j=0;

    indexDiff=(long)indexDiff;
    valueDiff=(long)valueDiff;
    multiset<long>mset;

    for(j=0; j<n; j++) {
      if(j>indexDiff) 
        mset.erase((long)nums[j-indexDiff-1]);

        auto it=mset.lower_bound((long)nums[j]-valueDiff);
        long diff=*it-(long)nums[j];
        if(it!=mset.end() && diff<=valueDiff)
          return true;

      mset.insert(nums[j]);
    }
    return false;
          
    }
};