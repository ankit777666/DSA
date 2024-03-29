class Solution {
public:
    int count(vector<int>&v) {
        int low=0, high=v.size()-1;
        int res=0;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(v[mid]<0) {
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return v.size()-high-1;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0; i<grid.size(); i++) {
            ans+=count(grid[i]);
        }
        return ans;
    }
};