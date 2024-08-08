class Solution {
public:
    int longestSubstring(string s, int k) {
      int n=s.size();
      int j=0;
      unordered_map<char,int>umap;
      for(int i=0; i<n; i++) {
        umap[s[i]]++;
      }
      while(j<n && umap[s[j]]>=k)
        j++;
      if(j==n)
        return n;
      int left = longestSubstring(s.substr(0,j),k);
      int right = longestSubstring(s.substr(j+1),k);
      return max(left, right);
    }
};