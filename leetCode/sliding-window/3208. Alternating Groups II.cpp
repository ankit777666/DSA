class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
      int i=0, j=0;
      int n=colors.size();
      int count=1;
      int ans=0;
      for(int i=1; i<n+k-1; i++) {
        if(colors[(i-1)%n] != colors[i%n]) {
          count++;
        }
        else {
          count=1;
        }
        if(count>=k)
          ans++;
      }
      return ans;   
    }
};