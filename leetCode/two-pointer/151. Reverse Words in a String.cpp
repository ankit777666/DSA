class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string temp="", ans="";
        for(int i=n-1; i>=0; i--) {
            if(s[i]==' ' && temp!="") {
                reverse(temp.begin(),temp.end());
                ans+=temp+' ';
                temp="";
            }
            else {
                if(s[i]==' ')
                    continue;
                temp+=s[i];
            }
        }
        reverse(temp.begin(), temp.end());
        ans+=temp;
        if(ans[ans.size()-1]==' ')
            ans.pop_back();
        return ans;
    }
};