class Solution{   
public:
    int countSmallEqual(vector<vector<int>> &matrix, int R, int C, int mid) {
        int count=0;
        for(int i=0; i<R; i++) {
            count+=upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        return count;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here   
        int low=INT_MAX, high=INT_MIN;
        for(int i=0; i<R; i++) {
            low=min(low,matrix[i][0]);
            high=max(high,matrix[i][C-1]);
        }
        int req=R*C/2;
        while(low<=high) {
            int mid=low+(high-low)/2;
            int count=countSmallEqual(matrix, R, C, mid);
            if(count<=req)
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
    }
};