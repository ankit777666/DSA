class Solution {
public:
    string minWindow(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        if(n2>n1) return "";
        int i=0,j=0,count=0;
        int start=0;
        unordered_map<char,int>umap;
        int minLen=INT_MAX;
        for(auto ch : t) {
          umap[ch]++;
        }

        while(j<n1) {
          if(umap.find(s[j])!=umap.end()) {
            umap[s[j]]--;
            if(umap[s[j]]>=0)
              count++;
          }
          while(count==n2) {
            if(minLen>j-i+1) {
              minLen=j-i+1;
              start=i;
            }        
            if(umap.find(s[i])!=umap.end()) {
              if(umap[s[i]]==0)
                count--;
              umap[s[i]]++;
              
            }
            i++;
          }
        j++;  
      }
      return minLen>n1 ? "" : s.substr(start,minLen);
    }
};