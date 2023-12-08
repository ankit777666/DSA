class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1=s.size();
        int n2=p.size();
        if(n1<n2) return {};
        vector<int>ans;
        int count=0;
        unordered_map<char, int> umap;
        int i=0, j=0;
        for(int i=0;i<n2; i++) {
            umap[p[i]]++;
        }
        while(j<n1) {
            if(umap.find(s[j])!=umap.end()) {
                umap[s[j]]--;
                if(umap[s[j]]==0) {
                    count++;
                }
            }
            if(count==umap.size()) {
                ans.push_back(i);
            }
            if(j>=n2-1) {
                if(umap.find(s[i])!=umap.end()) {
                    if(umap[s[i]]==0) {
                        count--;
                    }
                    umap[s[i]]++;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};