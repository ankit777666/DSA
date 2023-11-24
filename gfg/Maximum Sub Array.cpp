class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    vector<int> ans; int start=0, end=0;
	    int newStart = 0;
	    int max_so_far = INT_MIN;
	    int max_ending_here = 0;
	    
	    for(int i = 0; i < n; i++) {
	        if(a[i] <0) {
	            max_ending_here = 0;
	            newStart = i+1;
	        }
            else {
                max_ending_here+=a[i];
	            if(max_ending_here>max_so_far) {
	                max_so_far=max_ending_here;
	                start=newStart;
	                end = i+1;
	            }
	            else if(max_ending_here == max_so_far) {
	                int currDis = i+1-newStart;
	                int maxDis = end-start;
	                
	                if(currDis>maxDis) {
	                    start = newStart;
	                    end = i+1;
	                }
	            }
            }
	    }
	    for(int i=start; i<end; i++) {
	        ans.push_back(a[i]);
	    }
	    return ans;
	}
};