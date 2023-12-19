class Solution{
public:
    int findWinner(int n, int A[]){
        // code here
        int x = A[0];
        for(int i = 1; i < n; i++){
            x = x^A[i];
        }
        return x == 0 || n % 2 == 0 ? 1 : 2;
    }
};