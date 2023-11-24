int max_sum(int A[],int N)
{
//Your code here
    
    int index = 0;
    int ans = 0; 
    int currAns = 0; int sum = 0;
    
    for(int i=0; i<N; i++) {
        sum+=A[i];
        currAns+=i*A[i];
    }
    ans = currAns;
    
    for(int i = 1; i<N; i++) {
        currAns = currAns - (sum-A[i-1]) + A[i-1]* (N-1);
        ans = max(ans, currAns);
    }
    
    
    return ans;
    
}