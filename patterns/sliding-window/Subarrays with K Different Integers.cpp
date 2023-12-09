class Solution {
  public:
    int atmostCount(vector<int> &arr, int N, int k) {
        int i=0, j=0;
        unordered_map<int, int> umap;
        int ans=0;
        while(j<N) {
            umap[arr[j]]++;
            if(umap.size()>k) {
                while(umap.size()>k) {
                    umap[arr[i]]--;
                    if(umap[arr[i]]==0) {
                        umap.erase(arr[i]);
                    }
                i++;
                }
            }
            
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    
    int subarrayCount(vector<int> &arr, int N, int k) {
        // code here
        return atmostCount(arr,N, k) - atmostCount(arr,N, k-1);
        
    }
};