class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        if(num==1)
            return arr[0];
        
        int max_so_far = arr[0]; int min_so_far = arr[0];
        int max_ending_here = arr[0]; int min_ending_here = arr[0];
        int arrSum = 0;
        for(int i=0; i<num; i++) 
            arrSum+=arr[i];
        for(int i=1; i<num; i++) {
            max_ending_here = max(max_ending_here+arr[i], arr[i]);
            max_so_far = max(max_so_far, max_ending_here);
            
            min_ending_here = min(min_ending_here +arr[i], arr[i]);
            min_so_far = min(min_so_far, min_ending_here);
            
            
        }
        if(min_so_far == arrSum)
                return max_so_far;
        return max(max_so_far, arrSum-min_so_far);
    }
};