class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int i=0, j=0;
        int maxLen=INT_MIN;
        unordered_map<int, int>umap;
        while(j<n) {
          umap[fruits[j]]++;
          while(umap.size()>2) {
            umap[fruits[i]]--;
            if(umap[fruits[i]]==0)
              umap.erase(fruits[i]);
            i++;
          }
          maxLen=max(maxLen, j-i+1);
          j++;
        }
        return maxLen;
    }
};