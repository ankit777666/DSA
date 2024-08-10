class Solution {
public:
    int numberOfSubstrings(string s) {
      int n=s.size();
      int i=0, j=0;

      unordered_map<char,int>umap;
      int ans=0;

      while(j<n) {
        umap[s[j]]++;

        while(umap['a'] && umap['b'] && umap['c']) {
          ans+=n-j;//total number of substrings is 1+ elements outside window
          umap[s[i]]--;
          i++;
        }
        j++;

      }
      return ans;    
    }
};