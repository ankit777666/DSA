class Solution {
  public:
    int digit_sum(int n) {
        int sum=0;
        while(n>0) {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int smithNum(int n) {
        // code here
        int sum=0;
        int temp=n;
        if(n==2) return 0;
        while(n%2==0) {
            sum+=2;
            n=n/2;
            
        }
        for(int i=3; i<=temp/2; i=i+2) {
            while(n%i==0) {
                sum+=digit_sum(i);
                n=n/i;
            }
        }
        if(n>2 || sum!=digit_sum(temp))
            return 0;
        return 1;
    }
};