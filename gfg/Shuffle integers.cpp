class Solution{
	
	
	
	public:
	void shuffleArray(int arr[],int n)
	{
	    // Your code goes here
	    int mx = 1e4;
	    int start = 1, end = n/2;
	    for(int i=1; i<n; i++) {
	        if(i%2 !=0)
	            arr[i] = (arr[end++] % mx)* mx + (arr[i] % mx);
            else
                arr[i] = (arr[start++] % mx)* mx + (arr[i] % mx);
            
	    }
	    for(int i=1;i<n;++i)
            arr[i] /= mx;
	    
	}
		 

};