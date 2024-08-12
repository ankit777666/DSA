class Solution {
public:
    int minimumRecolors(string blocks, int k) {
      int n= blocks.size();
      int i=0, j=0;
      int ans=INT_MAX, curr=0;

      while(j<n) {
        if(blocks[j]=='W')
          curr++;
        // if(j-i+1<k)
        //   j++;
        // else {
        //   ans=min(ans,curr);
        //   j++;
        //   if(blocks[i]=='W')
        //     curr--;
        //   i++;
        // }
        if(j-i+1>=k) {
          ans=min(ans,curr);
          if(blocks[i]=='W')
            curr--;
          i++;
        }
        j++;
      }
      return ans;    
    }
};