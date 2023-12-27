class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int low=0, high=s.size()-1;
        string str=s;
        while(low<high) {
            if(s[low]!=s[high]) {
                str[high]=(s[low]<s[high]) ? s[low] : s[high];
                str[low]=str[high];
                
            }
            low++;high--;
        }
        return str;
    }
};