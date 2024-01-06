class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        if(s.size()==1) return -1;
        int i=s.size()-2;
        while(i>=0 && s[i]>=s[i+1]) {
            i--;
        }
        if(i==-1) return -1;
        reverse(s.begin()+i+1, s.end());
        for(int j=i+1; j<s.size(); j++) {
            if(s[j]>s[i]) {
                swap(s[j],s[i]);
                break;
            }
        }
        long ans=stol(s);
        if(ans==n || ans>INT_MAX)
            return -1;
        return ans;
    }
};