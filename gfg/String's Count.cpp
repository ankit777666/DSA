long long int countStr(long long int n){
    //complete the function here
    long long int ans=1;//for only aaaa
    ans+=2*n;
    ans+=n*(n-1);
    ans+=n*(n-1)*(n-2)/2;
    ans+=n*(n-1)/2;
    
    return ans;
}