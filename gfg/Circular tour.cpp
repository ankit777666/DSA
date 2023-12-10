class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int start=0;
       int shortage=0;
       int remaining=0;
       int j=0;
       while(j<n) {
           remaining+=p[j].petrol-p[j].distance;
           if(remaining<0) {
               shortage+=remaining;
               start=j+1;
               remaining=0;
           }
           j++;
       }
       if(remaining+shortage>=0)
            return start;
        return -1;
       
    }
};