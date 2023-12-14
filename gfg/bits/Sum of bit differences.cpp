class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    // code here
	    long long ans=0;
	    
	    for(int i=0; i<32; i++) {
	        long long countOn=0, countOff = 0;
	        for(int j=0; j<n; j++) {
	            if(arr[j]%2 != 0)
	                countOn++;
                else
                    countOff++;
                arr[j]/=2;
	        }
	        
	        ans+=countOn*countOff*2;
	    }
	    return ans;
	}
};