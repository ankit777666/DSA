class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>charSet;
        int l=0, r=0;
        int ans=0;
        while(r<s.size()) {
          if(charSet.count(s[r])==0) {
            charSet.insert(s[r]);
            ans=max(ans, r-l+1);
          }
          else {
            while(charSet.count(s[r])) {
              charSet.erase(s[l]);
              l++;
            }
            charSet.insert(s[r]);
          }
          r++;
        }
        return ans;
    }
};