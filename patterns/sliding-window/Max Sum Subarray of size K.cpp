class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        long maxSum = INT_MIN; long currSum = 0;
        int i=0, j=0;
        
        for(j=0; j<N; j++) {
            currSum +=Arr[j];
            if(j>=K-1) {
                maxSum=max(maxSum, currSum);
                currSum -=Arr[i];
                i++;
            }
        }
        return maxSum;
        
        
    }
};