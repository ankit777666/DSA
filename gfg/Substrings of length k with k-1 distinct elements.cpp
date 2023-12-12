class Solution {
  public:
    int countOfSubstrings(string S, int K) {
        // code here
        int n=S.size();
        int i=0, j=0;
        int ans=0;
        unordered_map<char, int> umap;
        while(j<n) {
            umap[S[j]]++;
            if(j-i+1<K) {
                j++;
            }
            else {
                if(umap.size()==K-1 && j-i+1==K) {
                    ans++;
                }
                umap[S[i]]--;
                if(umap[S[i]]==0) {
                    umap.erase(S[i]);
                }
                i++; j++;
            }
        }
        return ans;
    }
};