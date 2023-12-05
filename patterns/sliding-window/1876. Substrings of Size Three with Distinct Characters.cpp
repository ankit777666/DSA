class Solution {
public:
    int countGoodSubstrings(string s) {
        int n=s.size();
        int i=0, j=0;
        char str1,str2; int ans=0;
        unordered_map<char, int> umap;
        while(j<n) {
            str1=s[j];
            umap[str1]++;
            if(j-i+1<3)
                j++;
            else {
                if(umap.size()==3) {
                ans++;
                }
                str2=s[i];
                umap[str2]--;
                if(umap[str2] ==0)
                    umap.erase(str2);
                i++;
                j++;
            }
            
        }
        return ans;
    }
};