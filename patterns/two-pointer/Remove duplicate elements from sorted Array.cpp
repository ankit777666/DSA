class Solution{
public:
    int remove_duplicate(int a[],int n){
        // code here
        int index=1;
        for(int i=0; i<n; i++) {
            if(a[index-1]!=a[i]) {
                a[index]=a[i];
                index++;
            }
        }
        return index;
    }
};