class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
      int n=nums.size();
      priority_queue<pair<int,int>>pq;
      vector<int>sum=nums;
      pq.push({sum[0],0});

      int ans=sum[0];
      int j=1;
      while(j<n) {
        while(!pq.empty() && (j-pq.top().second>k))
          pq.pop();
        sum[j]=max(sum[j], sum[j]+pq.top().first);
        pq.push({sum[j],j});
        ans=max(ans, sum[j]);
        j++;
        
      }
      return ans;

    }
};