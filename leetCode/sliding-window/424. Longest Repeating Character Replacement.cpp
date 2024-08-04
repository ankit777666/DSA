class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0, j=0, count=0;
        unordered_map<char, int>umap;
        int maxLen=INT_MIN;

        while(j<n) {  
          umap[s[j]]++;
          count=max(count, umap[s[j]]);
          if(j-i+1-count>k) {
            umap[s[i]]--;
            i++;
          }
          maxLen=max(maxLen, j-i+1);
          j++;
        }
        return maxLen;
    }
};