class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        sort(houses.begin(), houses.end());
        int n1=houses.size(), n2=heaters.size();
        vector<int>ans(n1, INT_MAX);
        int i=0,j=0;
        while(i<n1 && j<n2) {
            if(houses[i]<=heaters[j]) {
                ans[i]=heaters[j]-houses[i];
                i++;
            }
            else {
                j++;
            }
        }
        i=n1-1, j=n2-1;
        while(j>=0 && i>=0) {
            if(houses[i]>=heaters[j]) {
                ans[i]=min(ans[i],houses[i]-heaters[j]);
                i--;
            }
            else {
                j--;
            }
        }
        
        return *max_element(ans.begin(), ans.end());
    }
};