class Solution
{
	public:
	    void find_permutationUtil(string S, int l,int r, vector<string>&ans) {
	        if(l==r) {
	            ans.push_back(S);
	            return;
	        }
	        unordered_set<char>s;
	        for(int i=l; i<=r; i++) {
	            if(s.find(S[i])!=s.end())
	                continue;
                s.insert(S[i]);
	            swap(S[i],S[l]);
	            find_permutationUtil(S, l+1,r, ans);
	            swap(S[i],S[l]);
	        }
	        
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string>ans;
		  //  sort(S.begin(), S.end());
		    int l=0, r=S.size()-1;
		    find_permutationUtil(S,l,r,ans);
		    //sort(ans.begin(), ans.end());
		    return ans;
		}
};