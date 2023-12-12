class Solution
{
  public:
    long long int substrCountUtil(string s, int k) {
    //     long long int n=s.size();
    // 	long long int i=0, j=0;
    // 	long long int ans=0;
    // 	unordered_map<char, long long int> umap;
    // 	while(j<n) {
    // 	    umap[s[j]]++;
    // 	    while(umap.size()>k) {
    // 	        umap[s[i]]--;
    // 	        if(umap[s[i]]==0) {
    // 	            umap.erase(s[i]);
    // 	        }
    // 	        i++;
    // 	    }
    // 	    j++;
    // 	    ans+=j-i+1;
    	        
	        
    // 	}
    // 	return ans;
        long long int n=s.size();
        long long int i=0, j=0, count=0;
        long long int ans=0;
        int v[26]={0};
        while(j<n) {
            v[s[j]-'a']++;
            if(v[s[j]-'a']==1) {
                count++;
            }
            while(count>k) {
                v[s[i]-'a']--;
                if(v[s[i]-'a']==0) {
                    count--;
                }
                i++;
            }
            
            ans+=j-i+1;
            j++;
            
        }
        return ans;
    
    }
  
    long long int substrCount (string s, int k) {
    	//code here.
    	
    	
    	return substrCountUtil(s,k) - substrCountUtil(s,k-1);
    }
};