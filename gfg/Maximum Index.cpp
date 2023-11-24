class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    { 
        // Your code here
        
        int minArray[N]; int maxArray[N];
        minArray[0] = A[0]; maxArray[N-1] = A[N-1];
        
        for(int i=1; i<N; i++)
            minArray[i] = min(minArray[i-1], A[i]);
        for(int i=N-2; i>=0; i--)
            maxArray[i] = max(maxArray[i+1], A[i]);
            
        int diff = 0;
        
        int i=0, j=0;
        while(i<N && j<N) {
            if(maxArray[j]>=minArray[i]) {
                diff = max(diff, j-i);
                j++;
            }
            else
                i++;
        }
        return diff;
    }
};