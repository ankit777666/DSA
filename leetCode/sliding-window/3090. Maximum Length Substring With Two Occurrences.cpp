class Solution {
public:
    int maximumLengthSubstring(string s) {
      int n=s.size();
      int i=0, j=0;
      int maxLen=INT_MIN;

      unordered_map<char,int> umap;
      while(j<n) {
        umap[s[j]]++;

        while(umap[s[j]]==3) {
          umap[s[i]]--;
          i++;
        }
        maxLen=max(maxLen, j-i+1);
        j++;
      }
      return maxLen;
    }
};