class Solution {
public:
    bool isPalindrome(string s, int low, int high) {
        while(low<=high) {
            if(s[low]!=s[high])
                return false;
            low++;high--;
        }
        return true;
    }
    bool util(string a, string b) {
        int i=0, j=a.size()-1;
        while(i<j && a[i]==b[j]) {
            i++;j--;
            
        }
        return isPalindrome(a, i,j) || isPalindrome(b,i,j);
    }
    bool checkPalindromeFormation(string a, string b) {
        return util(a,b) || util(b,a);
        
    }
};