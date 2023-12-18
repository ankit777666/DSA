class Solution{
public:
    bool isLuckyUtil(int counter, int n) {
        if(counter>n)
            return 1;
        if(n%counter==0)
            return 0;
        n=n-n/counter;
        counter++;
        return isLuckyUtil(counter, n);
    }
    bool isLucky(int n) {
        // code here
        
        return isLuckyUtil(2, n);
    }
};