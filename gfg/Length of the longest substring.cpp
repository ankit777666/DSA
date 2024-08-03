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

//space optimized
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        int n=S.size();
        //unordered_map<char,int> umap;
        vector<int>v(256,-1);
        
        int i=0, j=0;
        int maxLen=INT_MIN;
        while(j<n) {
            if(v[S[j]-'a'] != -1) {
                i=max(i, v[S[j]-'a']+1);
            }
            maxLen=max(maxLen, j-i+1);
            v[S[j]-'a']=j;
            j++;
        }
        return maxLen;
        
    }
};