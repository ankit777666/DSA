class Solution {
public:
    bool util(string s) {
      for(int i=0; i<s.size(); i++) {
        if(islower(s[i])) {
          char ch=toupper(s[i]);
          if(find(s.begin(),s.end(),ch)==s.end())
            return 0;
        }
        else {
          char ch=tolower(s[i]);
          if(find(s.begin(),s.end(),ch)==s.end())
            return 0;
        }
      }
      return 1;
    }

    string longestNiceSubstring(string s) {
      int n=s.size();
      if(n==1) return "";
      int maxLen=0;
      string ans="";

      for(int i=0; i<n; i++) {
        string str="";
        for(int j=i+1; j<n; j++) {
          str=s.substr(i,j-i+1);
          if(util(str)) {
            if(str.size()>maxLen) {
              ans=str;
              maxLen=str.size();
            }
          }
        }
      }
      return ans;    
    }
};