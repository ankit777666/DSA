class Solution {
public:
    int balancedString(string s) {
      int n=s.size();
      int eachCount=n/4;
      unordered_map<char,int>umap;
      int ans=INT_MAX;
      for(auto ch : s)
        umap[ch]++;
      
      int i=0, j=0;
      while(j<n) {
        umap[s[j]]--;
        while(i<n && umap['Q']<=eachCount && 
              umap['W']<=eachCount &&
              umap['E']<=eachCount &&
              umap['R']<=eachCount) {
                ans=min(ans,j-i+1);
                umap[s[i]]++;
                i++;
              }
        j++;
        
      }
      return ans;
    }
};