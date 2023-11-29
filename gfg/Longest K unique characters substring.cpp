class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int n=s.size();
        int i=0, j=0;
        int maxlen = -1;
        unordered_map<char, int> umap;
        
        while(j<n) {
            umap[s[j]]++;
            if(umap.size() > k) {
                while(umap.size() > k) {
                    umap[s[i]]--;
                    if(umap[s[i]] == 0)
                        umap.erase(s[i]);
                    i++;
                }
            }
            if(umap.size() == k)
                maxlen = max(maxlen, j-i+1);
            j++;
        }
        return maxlen;
        
    }
};