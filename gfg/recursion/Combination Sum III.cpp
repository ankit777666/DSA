class Solution {
  public:
    void combinationSumUtil(int index, int K,vector<int>arr, int N, vector<int>&v, vector<vector<int>>&ans) {
        
        if(K==0) {
            if(N==0) {
                ans.push_back(v);
                return;
            }
            
        }
        
        for(int i=index; i<9; i++) {
            if(i>index && arr[i]==arr[i-1]) {
                continue;
            }
            if(arr[i]>N) {
                break;
            }
            v.push_back(arr[i]);
            combinationSumUtil(i+1, K-1,arr, N-arr[i], v, ans);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(int K, int N) {
        // code here
        vector<vector<int>>ans;
        vector<int>v;
        int index=0;
        vector<int>arr={1,2,3,4,5,6,7,8,9};
        combinationSumUtil(index, K,arr, N, v, ans);
        return ans;
    }
};