class Solution {
public:
    int maxVowels(string s, int k) {
      int n=s.size();
      unordered_map<char,int>umap;
      int i=0, j=0;
      int ans=0;
      while(j<n) {
        umap[s[j]]++;
        while(j-i+1==k) {
          int count=umap['a']+umap['e']+umap['i']+umap['o']+umap['u'];
          ans=max(ans, count);
          umap[s[i]]--;
          i++;
        }
        j++;
      }    
      return ans;
    }
};