class Solution{
  public:
    long long countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long ans=0;
        long long currProd=1;
        
        int i=0, j=0;
        while(j<n) {
            currProd*=a[j];
            while(currProd>=k && i<j) {
                currProd=currProd/a[i];
                i++;
            }
            if(currProd<k)
                ans+=j-i+1;
            j++;
        }
        return ans;
    }
};