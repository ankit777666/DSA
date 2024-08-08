class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {

      int n=grid.size(), m=grid[0].size();
      int rowAns=0, colAns=0;

      for(int i=0; i<n; i++) {
        int count=0;
        int start=0, end=m-1;

        while(start<end) {
          if(grid[i][start] != grid[i][end]) 
            count++;
          start++; end--;
        }
        rowAns+=count;
      }
      for(int i=0; i<m; i++) {
        int count=0;
        int start=0, end=n-1;
        while(start<end) {
          if(grid[start][i] !=grid[end][i])
            count++;
          start++;end--;
        }
        colAns+=count;
      }
      return min(rowAns, colAns);    
    }
};