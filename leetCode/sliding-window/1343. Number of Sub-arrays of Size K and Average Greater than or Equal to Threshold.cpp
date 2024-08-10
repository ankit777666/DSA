class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
      int n=arr.size();
        if(n<k)
            return -1;
        int j=0;int sum=0;int ans=0;
        for(int i=0;i<n;i++) {
            sum+=arr[i];
            if(i-j+1==k) {
                if(sum/k>=threshold)
                    ans++;
                sum=sum-arr[j];
                j++;
            } 
        }
        return ans;    
    }
};