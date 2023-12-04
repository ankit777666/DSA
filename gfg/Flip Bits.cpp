class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int max_ending_here = 0;
        int max_so_far = 0;
        int count1 = 0;
        for(int i=0; i<n; i++) {
            max_ending_here += 1-2*a[i];
            count1+=a[i];
            if(max_ending_here>max_so_far)
                max_so_far = max_ending_here;
            
            if(max_ending_here<0) max_ending_here = 0;
        }
        return count1+max_so_far;
    }
};