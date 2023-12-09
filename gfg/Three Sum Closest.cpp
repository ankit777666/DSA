class Solution{
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        int n=arr.size();
        sort(arr.begin(), arr.end());
        int ans=INT_MIN; int minDiff=INT_MAX;
        int k=0;
        for(k=0; k<n;k++) {
            int ele1=arr[k];
            int i=k+1;
            int j=n-1;
            while(i<j) {
                int sum = arr[i]+arr[j]+ele1;
                if(sum==target) return target;
                if(abs(sum-target)<abs(ans-target)) {
                    ans=sum;
                }
                if(abs(sum-target)==abs(ans-target)) {
                    ans=max(ans, sum);
                }
                if(sum>target)
                    j--;
                else
                    i++;
            }
        }
        return ans;
        
    }
};