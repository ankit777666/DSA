class Solution{
  public:
    int numberOfSubarrays(vector<int>& arr, int N, int target){
        // code here
        int ans=0;
        int j=0, i=0;
        int sum=0;
        unordered_map<int, int> umap;
        while(j<N) {
            sum+=arr[j];
            if(sum==target)
                ans++;
            if(umap.find(sum-target)!=umap.end()) {
                ans+=umap[sum-target];
            }
            umap[sum]++;
            j++;
        }
        return ans;
    }
};