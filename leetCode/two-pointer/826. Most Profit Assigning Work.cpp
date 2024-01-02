class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=worker.size();
        sort(worker.begin(),worker.end());
        vector<pair<int,int>> arr(n);
        for(int i=0; i<n; i++) {
            arr[i]={difficulty[i],profit[i]};
        }
        sort(arr.begin(),arr.end());
        int ans=0, curr=0, i=0,j=0;
        while(i<n) {
            while(j<n && arr[j].first<=worker[i]) {
                curr=max(curr,arr[j].second);
                j++;
            }
            ans+=curr;
            i++;
        }
        return ans;
    }
};