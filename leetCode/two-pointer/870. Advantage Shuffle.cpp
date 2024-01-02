class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        sort(nums1.begin(), nums1.end());
        vector<int> ans(n);
        priority_queue<pair<int,int>>pq;
        for(int i=0; i<n; i++) {
            pq.push({nums2[i],i});
        }
        int i=0, j=n-1;
        while(!pq.empty()) {
            pair<int,int> ele=pq.top();
            if(ele.first<nums1[j]) {
                ans[ele.second]=nums1[j];
                j--;
                pq.pop();
            }
            else {
                ans[ele.second]=nums1[i];
                i++;
                pq.pop();
            }
        }
        return ans;

    }
};