class Solution {
public:
    void util(int index, int n, int k, vector<int>&v, vector<vector<int>>&ans) {
        if(k==0) {
            ans.push_back(v);
            return;
        }
        for(int i=index; i<=n; i++) {
            v.push_back(i);
            util(i+1,n, k-1, v, ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>v;
        if(k>n)
            return ans;
            int index=1;
        util(index,n,k,v,ans);
        return ans;
    }
};