class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0, j=1,count=1;
        while(j<=n) {
            if(j==n || chars[j]!=chars[j-1]) {
                chars[i++]=chars[j-1];
                if(count>=2) {
                    for(char dig: to_string(count)) {
                        chars[i++]=dig;
                    }
                }
                
                count=0;
            }
            count++;
            j++;
        }
        return i;
    }
};