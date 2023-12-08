class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        int count = 0;
        unordered_map<char, int> umap1;
        for(int i=0; i<n1; i++)
            umap1[s1[i]]++;
        int i=0, j=0;
        while(j<n2) {
            if(umap1.find(s2[j])!=umap1.end()) {
                umap1[s2[j]]--;
                if(umap1[s2[j]]==0) {
                    count++;
                }
            }
            if(count==umap1.size())
                return true;
            if(j>=n1-1) {
                
                if(umap1.find(s2[i])!=umap1.end()) {
                    if(umap1[s2[i]]==0) {
                        count--;
                    }
                    umap1[s2[i]]++; 
                      
                }
                i++;
            }
            j++;
        }
        return false;
    }
};