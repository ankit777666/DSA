class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(tokens.begin(), tokens.end());
        int ans=0, count=0;
        int i=0,j=n-1;
        while(i<=j) {
            if(power>=tokens[i]) {
                power=power-tokens[i];
                count+=1;
                ans=max(ans,count);
                i++;
            }
            else if(count>0) {
                count--;
                power+=tokens[j];
                j--;
            }
            else {
                break;
            }    
        }
        return ans;
    }
};