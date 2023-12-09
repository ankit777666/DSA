class Solution {
  public:
    long long maxScore(vector<int> &cardPoints, int N, int k) {
        // code here
        long long ans; long long currSum=INT_MAX;
        long long sum=0; long long arrSum=0;
        int j=0,i=0;
        for(int i=0; i<N; i++)
            arrSum+=cardPoints[i];
        if(N-k==0) return arrSum;
        while(j<N) {
            sum+=cardPoints[j];
            if(j-i+1<N-k) {
                j++;
            }
            
            else if(j-i+1== N-k) {
                currSum=min(sum, currSum);
                sum-=cardPoints[i];
                i++;
                j++;
            }
            
        }
        return arrSum-currSum;
        
    }
};