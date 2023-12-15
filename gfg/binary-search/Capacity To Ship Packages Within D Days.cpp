class Solution {
  public:
    
    int calculateDays(int arr[], int N, int mid) {
        int days=1; int load=0;
        for(int i=0; i<N; i++) {
            if(load+arr[i]>mid) {
                days+=1;
                load=arr[i];
            }
            else {
                load+=arr[i];
            }
        }
        return days;
    }
     
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        int totalWeight=0;
        for(int i=0; i<N; i++)
            totalWeight+=arr[i];
        // sort(arr,arr+N);
        int maxWeight=*max_element(arr, arr+N);
        int capacity=maxWeight;
        int low=maxWeight, high=totalWeight;
        while(low<=high) {
            int mid=(low+high)/2;
            int days = calculateDays(arr, N, mid);
            if(days<=D) {
                
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return low;
        
    }
};