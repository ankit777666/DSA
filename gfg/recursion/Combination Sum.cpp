class Solution {
  public:
  
    void combinationSumUtil(vector<int>&arr, int B, vector<vector<int>> &ans,vector<int>&temp, int index) {
        if(index==arr.size()) {
            if(B==0) {
                ans.push_back(temp);
            }
            return;
        }
        
        if(B>=arr[index]) {
            temp.push_back(arr[index]);
            combinationSumUtil(arr, B-arr[index], ans, temp, index);
            temp.pop_back();
        }
        combinationSumUtil(arr, B, ans, temp, index+1);
        
    }
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        set<int>st(A.begin(),A.end());
        vector<int>arr(st.begin(),st.end());
        int index=0;
        vector<vector<int>> ans;
        vector<int> temp;
        
        combinationSumUtil(arr, B, ans, temp,  index);
        return ans;
    }
};