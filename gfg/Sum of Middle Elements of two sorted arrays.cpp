class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n) {
            // code here 
        int n1 = n;
        int n2 = n;
        int N=n1+n2;
        if(n1>n2) return findMidSum(ar2, ar1, n);
        
        int low=0, high = n1;
        int left = (n1+n2+1)/2;
        while(low<=high) {
            int mid1 = (low+high) >>1;
            int mid2 = left-mid1;
            int l1=INT_MIN; int l2=INT_MIN;
            int r1=INT_MAX; int r2=INT_MAX;
            
            if(mid1<n1) r1=ar1[mid1];
            if(mid2<n2) r2=ar2[mid2];
            if(mid1-1>=0) l1=ar1[mid1-1];
            if(mid2-1>=0) l2=ar2[mid2-1];
            
            if(l1<=r2 && l2<=r1) {
                if(N%2==1)
                    return l1+l2;
                return (max(l1,l2)+min(r1,r2));
            }
            else if(l1>r2)
                high=mid1-1;
            else
                low=mid1+1;
        }
    }
};