class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        int close=0, maxClose=0;
        int j=0;
        int ans=0;
        while(j<n) {
           if(s[j]==']') {
               close++;
               maxClose=max(close, maxClose);
           }
           if(s[j]=='[') {
               close--;
           }
           j++;
        }
        ans = (maxClose+1)/2;
        return ans;
    }
};