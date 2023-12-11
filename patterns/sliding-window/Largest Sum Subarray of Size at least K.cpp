long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
    long long int i=0, j=0;
    long long int ans=INT_MIN;
    long long sum=0;
    long long last=0;
    
    while(j<n) {
        sum+=a[j];
        if(j-i+1==k) {
            ans=max(ans, sum);
        }
        else if(j-i+1>k) {
            ans=max(ans, sum);
            last+=a[i];
            i++;
            if(last<0) {
                sum-=last;
                ans=max(ans, sum);
                last=0;
            }
        }
        
        j++;
    }
    return ans;
    
}