class Solution {
public:
    int appendCharacters(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        int match=0;
        int i=0,j=0;
        while(i<n1) {
            if(s[i]==t[j]) {
                i++; j++;
                match++;
            }
            else {
                i++;
            }
                
        }
        return n2-match;
    }
};