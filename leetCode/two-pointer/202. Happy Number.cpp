class Solution {
public:
    bool isHappy(int n) {
        set<int>s;
        while(true) {
            int val=0;
            while(n) {
                int dig=n%10;
                val+=dig*dig;
                n=n/10;
            }
            if(val==1)
                return true;
            if(s.find(val)!=s.end())
                return false;
            s.insert(val);
            n=val;
        }
        return false;

    }
};