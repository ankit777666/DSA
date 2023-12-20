class Solution{
public:
    string rremove(string s){
        // code here
        string temp=""; bool flag=true;
        for(int i=0; i<s.size(); i++) {
            if(s[i]==s[i+1]) {
                flag=false;
                while(s[i]==s[i+1]) {
                    i++;
                }
            }
            else {
                temp.push_back(s[i]);
            }
            
        }
        if(flag==true)
            return temp;
        
        return rremove(temp);
    }
};