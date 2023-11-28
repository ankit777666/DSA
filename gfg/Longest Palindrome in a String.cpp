class Solution {
  public:
    string longestPalin (string S) {
        // code here
        int n = S.size();
        int start = 0, end =0, maxLength = 1;
        
        for(int i=0; i<n; i++) {
            int l=i, r=i;
            while(l>=0 && r<n) {
                if(S[l] != S[r])
                    break;
                l--; r++;
            }
            int currLength = r-l-1;
            if(currLength>maxLength) {
                maxLength = currLength;
                start = l+1; end = r-1;
            }
        }
        
        for(int i=0; i<n; i++) {
            int l=i, r=i+1;
            while(l>=0 && r<n) {
                if(S[l] != S[r])
                    break;
                l--; r++;
            }
            int currLength = r-l-1;
            if(currLength>maxLength) {
                maxLength = currLength;
                start = l+1; end = r-1;
            }
        }
        return S.substr(start, maxLength);
    }
};