class Solution{   
public:

    string add_string(string num1, string num2) {
        int i = num1.size()-1;
        int j = num2.size()-1;
        string output = "";
        int carry = 0;
        while(i>=0 || j>=0 || carry) {
            int sum = carry;
            if(i>=0) {
                sum+=num1[i--]- '0';
            }
            if(j>=0) {
                sum+=num2[j--]- '0';
            }
            int rem = sum%10;
            carry=sum/10;
            output.push_back(rem+'0');
        }
        reverse(output.begin(), output.end());
        return output;
    }
    
    bool isSumStringUtil(string S, int start, int len1, int len2, int n) {
        string s1 = S.substr(start, len1);
        string s2 = S.substr(start+len1, len2);
        string s3 = add_string(s1, s2);
        int s3_len = s3.length();
        if(s3_len > n-len1-len2-start) {
            return false;
        }
        if(s3 == S.substr(start+len1+len2,s3_len)) {
            if(start+len1+len2+s3_len ==n)
                return true;
            return isSumStringUtil(S, start+len1, len2, s3_len, n);
        }
        return false;
    }
    
    int isSumString(string S){
        // code here 
        int n=S.size();
        for(int i=1; i<n; i++) {
            for(int j=1; i+j<n; j++) {
                if(isSumStringUtil(S,0, i, j,n)) {
                    return true;
                }
            }
        }
        return false;
    }
};