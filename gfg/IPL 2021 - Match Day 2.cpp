class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> ans;
        priority_queue<pair<int,int>>pq;
       for(int i=0;i<k;i++)
       {
           pq.push({arr[i],i});
       }
       ans.push_back(pq.top().first);
       //for remaining elemnts
       for(int i=k;i<n;i++)
       {
           pq.push({arr[i],i});
           
         
               while(!pq.empty() and pq.top().second<=(i-k))
               {
                   pq.pop();
               }
           
           ans.push_back(pq.top().first);
           
       }
       return ans;
    }
};