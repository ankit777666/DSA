class Solution {
	public:
		int characterReplacement(string s, int k){
		    // Code here
		    int ans=0; int count = 0;
		    int i=0, j=0;
		    int n=s.size();
		    unordered_map<char, int> umap;
		    
		    while(j<n) {
		        umap[s[j]]++;
		        count = max(count, umap[s[j]]);
		        if(j-i+1 - count > k) {
		            umap[s[i]]--;
		            i++;
		        }
		        ans=max(ans, j-i+1);
		        j++;
		    }
		    return ans;
		}

};