class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0; i<n; i++) {
            int diff=abs(arr[i]-x);
            pq.push({diff,arr[i]});
            if(pq.size()>k)
                pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()) {
            auto ele=pq.top();
            ans.push_back(ele.second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};