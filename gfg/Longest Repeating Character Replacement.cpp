class Solution {
  public:
    int characterReplacement(string S, int K) {
        // code here
        int n=S.size();
        int i=0, j=0;
        unordered_map<char, int> umap;
        int ans=0; int count=0;
        
        while(j<n) {
            umap[S[j]]++;
            count=max(count, umap[S[j]]);
            if(j-i+1-count>K) {
                umap[S[i]]--;
                i++;
            }
            ans=max(ans, j-i+1);
            j++;
            
        }
        return ans;
    }
};