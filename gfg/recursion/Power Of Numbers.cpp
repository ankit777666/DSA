class Solution{
    public:
    //You need to complete this fucntion
    
    
    long long power(int N,int R)
    {
       //Your code here
       int mod=1e9+7;
       if(R==0) return 1;
       long long ans;
       if(R%2==0) {
           ans=power(N,R/2);
           ans=(ans*ans)%mod;
       }
       else {
           ans=N;
           ans=(ans*power(N, R-1))%mod;
       }
       return ans%mod;
       
        
    }

};