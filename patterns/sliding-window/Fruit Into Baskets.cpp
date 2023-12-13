class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        int i=0, j=0;
        int ans=0;
        unordered_map<int, int> umap;
        
        while(j<N) {
            umap[fruits[j]]++;
            if(umap.size()>2) {
                umap[fruits[i]]--;
                if(umap[fruits[i]]==0) {
                    umap.erase(fruits[i]);
                }
                i++;
            }
            ans=max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};