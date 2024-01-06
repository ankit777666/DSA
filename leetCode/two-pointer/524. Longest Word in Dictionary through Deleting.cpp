class Solution {
public:
    bool util(string str, string s) {
        int i=0,j=0;
        while(i<str.size() && j<s.size()) {
            if(str[i]==s[j])
                i++;
            j++;
        }
        return i==str.size();
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans="";
        for(auto str: dictionary) {
            if(util(str,s)) {
                if(str.size()>ans.size() || (str.size() ==ans.size() && str<ans)) {
                    ans=str;
                }
            }
        }
        return ans;
    }
};