class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        int i=0, j=0;
        int ans=0; int distinct;
        unordered_map<int, int> umap;
        for(int i=0; i<n; i++) {
            umap[arr[i]]++;
        }
        distinct=umap.size();
        umap.clear();
        while(j<n) {
            umap[arr[j]]++;
            while(umap.size()==distinct) {
                ans+=n-j;
                umap[arr[i]]--;
                if(umap[arr[i]]==0) {
                    umap.erase(arr[i]);
                }
                i++;
            }
            
            j++;
        }
        return ans;
        
    }
};