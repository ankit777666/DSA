class Solution {
  public:
    int canReach(int A[], int N) {
        // code here
        int maxR= 0;
        for(int i=0;i<N-1;i++){
            maxR = max(maxR,A[i]);
            if(maxR==0)return 0;
            maxR--;
        }
        return 1;
    }
};