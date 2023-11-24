class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int N) {
        // Your code here
        vector<int> ans;
        for(int i=0;i<N+2; i++) {
            int j = abs(arr[i]);
            
            if(arr[j]<0)
                ans.push_back(j);
            else
                arr[j] = -arr[j];
        }
        return ans;
    }
};

