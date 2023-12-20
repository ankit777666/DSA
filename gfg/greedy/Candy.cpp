class Solution {
  public:
    int minCandy(int N, vector<int> &ratings) {
        // code here
        int ans=0;
        vector<int>left(N,1); vector<int>right(N,1);
        for(int i=1; i<N;i++) {
            if(ratings[i]>ratings[i-1]) {
                left[i]=left[i-1]+1;
            }
                
        }
        for(int i=N-1; i>0; i--) {
            if(ratings[i]<ratings[i-1]) {
                right[i-1]=right[i]+1;
            }
        }
        for(int i=0; i<N; i++) {
            ans+=max(left[i],right[i]);
        }
        return ans;
    }
};