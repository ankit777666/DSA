class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n > 3) return false;
        if(n == 1) return true;
        else {
            if(s[0] == '0') return false;
            int x = stoi(s);
            if(x > 255) return false;
            return true;
        }
    }
    void util(int index, int dots, string &temp, string s, vector<string>&ans) {
        if(dots==4 && index==s.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i=index; i<s.size() && i<index+3; i++) {
            string str=s.substr(index, i-index+1);
            if(isValid(str)) {
                int size= temp.size();
                temp+=str;
                if(dots<3)
                    temp+=".";
                util(i+1, dots+1, temp, s, ans);
                temp.resize(size);
            }
            if(s[index]=='0')
                break;
        }
        
        
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        string temp="";
        int n=s.size();
        if(n>12) return ans;
        int index=0; int dots=0;
        util(index,dots, temp,s, ans);
        return ans;
        
    }
};