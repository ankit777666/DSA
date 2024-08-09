class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
    /*
      int n=arr.size();
      vector<int>dp1(n,1);
      vector<int>dp2(n,1);

      int maxLen=1;
      for(int i=1;i<n; i++) {
        if(arr[i]>arr[i-1])
          dp1[i]=dp2[i-1]+1;
        else if(arr[i]<arr[i-1])
          dp2[i]=dp1[i-1]+1;
        maxLen=max({maxLen, dp1[i],dp2[i]});
      }
      return maxLen; 
    }
    */

    int n=arr.size();
    int increment=1, decrement=1;
    int maxLen=1;

      for(int i=1; i<n; i++) {
        if(arr[i]<arr[i-1]) {
          decrement=increment+1;
          increment=1;
        }
        else if(arr[i]>arr[i-1]) {
          increment=decrement+1;
          decrement=1;
        }
        else {
          increment=1;
          decrement=1;
        }
        maxLen=max({maxLen, increment, decrement});
      }
      return maxLen;
    }
};