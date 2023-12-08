class Solution
{
    public:
    int isPrime(int n) {
        if(n==1)
            return 0;
        else if(n==2 || n==3)
            return 1;
        else if(n%2==0 || n%3==0)
            return 0;
        else {
            for(int i=5; i<n/2; i+=6) {
                if(n%i==0 || n%(i+2)==0)
                    return 0;
            }
        }
        return 1;
    }
    int minNumber(int arr[],int N)
    {
        int sum=0;
        int ans = 0;
        
        for(int i=0; i<N; i++) {
            sum+=arr[i];
        }
        while(isPrime(sum) !=1) {
            sum++;
            ans+=1;
        }
        return ans;
        
        
    }
};