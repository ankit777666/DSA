class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> s, e;
        int n=intervals.size();
        for(int i=0; i<n; i++) {
            s.push_back(intervals[i][0]);
            e.push_back(intervals[i][1]);
        }
        sort(s.begin(), s.end());
        sort(e.begin(),e.end());
        int i=0, j=0;
        int count=0,ans=0;
        while(i<n && j<n) {
            if(s[i]<=e[j]) {
                count++;
                i++;
            }
            else {
                count--;
                j++;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};