class Solution{
public:
    void combinationSum2Util(vector<int>arr, int n, int k, vector<int>&v, vector<vector<int>>&ans, int index) {
        if(k==0) {
            ans.push_back(v);
            return;
        }
        for(int i=index; i<n;i++) {
            if(i>index && arr[i]==arr[i-1]) continue;
            if(arr[i]>k)
                break;
            v.push_back(arr[i]);
            combinationSum2Util(arr,n, k-arr[i], v, ans, i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> v;
        int index=0;
        combinationSum2Util(arr, n, k, v,ans, index);
        return ans;
    }
};