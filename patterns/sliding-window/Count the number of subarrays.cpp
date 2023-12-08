class Solution {
  public:
    long long countSubarrayUtil(int N,vector<int> A,long long target) {
        long long ans=0;
        long long sum=0;
        int i=0,j=0;
        
        while(j<N) {
            sum+=A[j];
            while(sum>target) {
                sum-=A[i];
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    
    long long countSubarray(int N,vector<int> A,long long L,long long R) {
        // code here
        return countSubarrayUtil(N,A,R)-countSubarrayUtil(N,A,L-1);
        
    }
};