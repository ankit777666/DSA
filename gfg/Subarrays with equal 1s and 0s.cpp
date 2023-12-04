class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        int ans =0; int sum = 0;
        unordered_map<int, int>umap;
        
        for(int i=0; i<n; i++) {
            if(arr[i] ==0)
                arr[i] = -1;
        }
        for(int i=0; i<n; i++) {
            sum+=arr[i];
            if(sum==0)
                ans++;
            if(umap.find(sum)!=umap.end()) {
                ans+=umap[sum];
            }
            umap[sum]++;
        }
        return ans;
        
        
    }
};