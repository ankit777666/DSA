class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        long long mod=1e9+7;
        long long same = 0, diff = k;

        for (int i = 2; i <= n; i++) {
            long long prevSame = same;
            same = diff;
            diff = (prevSame + diff) * (k - 1) % mod;
        }
    
        return (same + diff) % mod;
    }
};