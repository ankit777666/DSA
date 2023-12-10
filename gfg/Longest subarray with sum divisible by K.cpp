class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    int i=0, j=0;
	    int ans=0, sum=0;
	    unordered_map<int, int> umap;
	    while(j<n) {
	        sum+=arr[j];
	        int rem=sum%k;
	        if(rem==0) {
	            ans= max(ans, j+1);
	        }
	        if(rem<0)
	            rem+=k;
	        if(umap.find(rem)!=umap.end()) {
	            ans=max(ans,j- umap[rem]);
	        }
	        else {
	            umap[rem]=j;
	        }
	        j++;
	    }
	    return ans;
	}
};