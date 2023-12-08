class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int ans=0; int count=0;
	    int n1=txt.size();
	    int n2=pat.size();
	    if(n2>n1) return 0;
	    unordered_map<char, int> umap;
	    for(int i=0; i<n2; i++)
	        umap[pat[i]]++;
	        
        int i=0, j=0;
        while(j<n1) {
            if(umap.find(txt[j])!=umap.end()) {
                umap[txt[j]]--;
                if(umap[txt[j]]==0) {
                    count++;
                }
            }
            if(count==umap.size()) {
                ans++;
            }
            if(j>=n2-1) {
                if(umap.find(txt[i])!=umap.end()) {
                    if(umap[txt[i]]==0) {
                        count--;
                    }
                    umap[txt[i]]++;
                }
                i++;
            }
            j++;
        }
        return ans;
	}

};