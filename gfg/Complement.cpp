class Solution{
public:
    vector<int> findRange(string str, int n) {
        // code here
        int l=-1, r=-1, start=1, sum=0, maxSum=0;
        for(int i=0; i<n; i++) {
            if(str[i]=='0') {
                sum++;
            }
            else {
                sum--;
            }
            if(sum>maxSum) {
                 maxSum=sum;
                 l=start;
                 r=i+1;
            }
            if(sum<0) {
                sum=0;
                start=i+2;
            }
        }
        if(l==-1)
            return {-1};
        return {l,r};
    }
};