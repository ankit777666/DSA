class Solution {
public:
    bool util(int index, vector<int>& matchsticks, int l1, int l2, int l3, int l4) {
        if(index==matchsticks.size()) {
            if(l1==0 && l2==0 && l3==0 && l4==0) {
                return true;
            }
            else
                return false;
        }
        if(matchsticks[index]<=l1) {
            l1-=matchsticks[index];
            if(util(index+1, matchsticks, l1, l2, l3, l4)) {
                return true;
            }
            l1+=matchsticks[index];
        }
        if(matchsticks[index]<=l2) {
            l2-=matchsticks[index];
            if(util(index+1, matchsticks, l1, l2, l3, l4)) {
                return true;
            }
            l2+=matchsticks[index];
        }
        if(matchsticks[index]<=l3) {
            l3-=matchsticks[index];
            if(util(index+1, matchsticks, l1, l2, l3, l4)) {
                return true;
            }
            l3+=matchsticks[index];
        }
        if(matchsticks[index]<=l4) {
            l4-=matchsticks[index];
            if(util(index+1, matchsticks, l1, l2, l3, l4)) {
                return true;
            }
            l4+=matchsticks[index];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()<4) return false;
        sort(matchsticks.begin(), matchsticks.end());
        int sum=0; int index=0;
        for(int i=0; i<matchsticks.size(); i++) {
            sum+=matchsticks[i];
        }
        if(sum%4!=0) return false;
        sum/=4;
        int l1=sum, l2=sum, l3=sum, l4=sum;
        return util(index, matchsticks, l1, l2,l3, l4);
        
        
    }
};

////optimized
class Solution {
public:
    bool util(int index, vector<int>& matchsticks, int sum, vector<int>&sides) {
        if(index==matchsticks.size()) {
            if(sides[0]==sides[1] && sides[1]==sides[2] &&
                sides[2]==sides[3]) {
                    return true;
                }
            else {
                return false;
            }
        }
        for(int i=0; i<4; i++) {
            if(sides[i]+matchsticks[index]>sum)
                continue;
            int j=i-1;
            while(j>=0) {
                if(sides[j]==sides[i])
                    break;
                j--;
            }
            if(j!=-1)
                continue;
            sides[i]+=matchsticks[index];
            if(util(index+1, matchsticks, sum, sides)) {
                return true;
            }
            sides[i]-=matchsticks[index];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()<4) return false;
        sort(matchsticks.begin(), matchsticks.end(),greater<int>());
        int sum=0; int index=0;
        for(int i=0; i<matchsticks.size(); i++) {
            sum+=matchsticks[i];
        }
        if(sum%4!=0) return false;
        sum/=4;
        vector<int>sides(4,0);
        return util(index, matchsticks, sum,sides);
        
        
    }
};