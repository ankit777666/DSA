class Solution {
  public:
    int gameOfXor(int N , int A[]) {
        // code here
        int ans=0;
        for(int i=0; i<N; i++) {
            if((i+1)*(N-i) %2 ==1)
                ans^=A[i];
        }
        return ans;
    }
};