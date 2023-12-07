class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here 
        int n=str.size();
        int i=0, j=0;
        int ans = INT_MAX;
        int distinct = 0;
        unordered_map<char, int> umap;
        // int freq[256] = {0};
        // for(int i=0; i<n; i++) {
        //     if(freq[str[i]]==0)
        //         distinct++;
        //     freq[str[i]]++;
        // }
        for(int i=0; i<n; i++) {
            umap[str[i]]++;
        }
        distinct=umap.size();
        umap.clear();
        
        while(j<n) {
            umap[str[j]]++;
            if(umap.size()<distinct)
                j++;    
            else if(umap.size()==distinct) {
                while(umap.size()==distinct) {
                    ans = min(ans,j-i+1);
                    umap[str[i]]--;
                    if(umap[str[i]]==0) {
                        umap.erase(str[i]);
                    }
                    i++;    
                }
                j++;
            }
        }
        return ans;
    }
};