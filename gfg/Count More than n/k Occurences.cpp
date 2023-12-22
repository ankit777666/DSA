class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        // Your code here
        int ans=0;
        unordered_map<int, int>umap;
        
        for(int i=0; i<n; i++ ) {
            umap[arr[i]]++;
        }
        for(auto i: umap) {
            if(i.second>n/k)
                ans++;
        }
        return ans;
    }
};