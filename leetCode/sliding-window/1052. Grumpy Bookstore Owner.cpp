class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
      int n=customers.size();
      int sum=0, currSum=0;
      int increase=0;
      int j=0;
      for(int i=0; i<n; i++)
        if(grumpy[i]==0)
          sum+=customers[i];
      
      while(j<n) {
        if(grumpy[j]==1)
          currSum+=customers[j];
        
        if(j>=minutes && grumpy[j-minutes]==1)
          currSum-=customers[j-minutes];
        
        increase=max(increase, currSum);
        j++;
      }
      return sum+increase;

    }
};