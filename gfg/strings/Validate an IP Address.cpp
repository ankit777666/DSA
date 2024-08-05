class Solution {
  public:
    int isValid(string str) {
        // code here
        int n=str.size();
        int j=0;
        string s="";
        while(j<n) {
            
            if(str[j] != '.') {
                s+=str[j];
                j++;
            }
            else {
                if(!s.empty() && stoi(s)>=0 && stoi(s)<=255) {
                    j++;
                    s="";
                }
                else
                    return 0;
            }
        }
        if(!s.empty() && stoi(s)>=0 && stoi(s)<=255)
            return 1;
        return 0;
    }
};