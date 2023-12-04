long long maxArea(long long A[], int len)
{
    // Your code goes here
    
    int left=0; int right=len-1;
    long long ans=0;
    
    while(left<right) {
        int width = right-left;
        if(A[left]<A[right]) {
            ans= max(ans, A[left]*width);
            left++;
        }
        else {
            ans= max(ans, A[right]*width);
            right--;
        }
    }
    return ans;
        
}