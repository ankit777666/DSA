class Solution {
public:
    int getMinSwaps(string num, int k) {
        int n=num.size();
        string str=num;
        int ans=0;
        while(k>0) {
            next_permutation(num.begin(), num.end());
            k--;
        }
        int i=0, j=0;
        while(i<n) {
            j=i;
            while(str[j]!=num[i])
                j++;
            while(i<j) {
                swap(str[j],str[j-1]);
                j--;
                ans++;
            }
            i++;
        }
        return ans;
    }
};