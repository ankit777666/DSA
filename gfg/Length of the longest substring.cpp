class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        int n=S.size();
        int i=0, j=0;
        int ans=0;
        unordered_map<char,int> umap;
        while(j<n) {
            if(umap.find(S[j])!=umap.end()) {
                i=max(i, umap[S[j]]+1);
            }
            umap[S[j]]=j;
            ans=max(ans, j-i+1);
            j++;
        }
        return ans;
        
    }
};