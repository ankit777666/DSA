class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        vector<int> ans;
        int i=0, j=0;
        unordered_map<int, int> umap;
        while(j<n) {
            umap[A[j]]++;
            if(j-i+1==k) {
                ans.push_back(umap.size());
                umap[A[i]]--;
                if(umap[A[i]]==0)
                    umap.erase(A[i]);
                i++;
            }
            
            j++;
        }
        return ans;
    }
};