class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        // Your code here
        vector<int> ans;
        
        vector<int>minLeft(N, -1);
        vector<int>maxRight(N, -1);
        int minIndex = 0; int maxIndex = N-1;
        
        for(int i=1; i<N; i++) {
            if(arr[i]<= arr[minIndex]) {
                minLeft[i] = -1;
                minIndex = i;
            }
            else {
                minLeft[i] = minIndex;
            }
        }
        
        for(int i=N-2; i>=0; i--) {
            if(arr[i]>=arr[maxIndex]) {
                maxRight[i] = -1;
                maxIndex = i;
            }
            else {
                maxRight[i] = maxIndex;
            }
        }
        
        for(int i=0; i<N; i++) {
            if(minLeft[i] != -1 && maxRight[i] != -1) {
                ans.push_back(arr[minLeft[i]]);
                ans.push_back(arr[i]);
                ans.push_back(arr[maxRight[i]]);
                return ans;
            }
        }
        return {};
    }
};