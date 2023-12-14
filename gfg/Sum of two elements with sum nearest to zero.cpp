class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
            // your code here 
            sort(arr, arr+n);
            int start=0, end=n-1;
            
            int ans=INT_MAX;
            int currSum=0;
            while(start<end) {
                int currSum=arr[start]+arr[end];
                if(currSum==0)
                    return 0;
                if(abs(currSum)<abs(ans) || abs(currSum)==abs(ans) && currSum>ans) {
                    ans=currSum;
                }
                if(currSum<0)
                    start++;
                else 
                    end--;
            }
            return ans;
        }
};