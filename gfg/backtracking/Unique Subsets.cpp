class Solution
{
    public:
    
    void allSubsetsUtil(int index, vector<int>arr, int n, vector<int>&v, vector<vector<int>>&ans) {
        
        ans.push_back(v);
            
        
        for(int i=index; i<n; i++) {
            if(i>index && arr[i]==arr[i-1])
                continue;
            v.push_back(arr[i]);
            allSubsetsUtil(i+1, arr, n, v, ans);
            v.pop_back();
        }
    }
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        sort(arr.begin(), arr.end());
        vector<vector<int>>ans;
        vector<int>v;
        int index=0;
        allSubsetsUtil(index, arr,n, v, ans);
        return ans;
    }
};