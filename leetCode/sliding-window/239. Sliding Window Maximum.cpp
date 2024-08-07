class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        int i=0, j=0;
        
        while(j<nums.size()) {
          while(j-i<k)
            pq.push({nums[j], j++});
          while(!pq.empty() && j-pq.top().second >k)
            pq.pop();
          ans.push_back(pq.top().first);
          i++;
        }
        return ans;
    }
};