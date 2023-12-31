class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int i=0, j=n-1;
        int len=n;
        while(i<j && s[i]==s[j]) {
            char ch=s[i];
            while(s[i]==ch && i<n) i++;
            while(s[j]==ch && j>0) j--;
            if(j<i)
                return 0;
        }
        return j-i+1;
    }
};