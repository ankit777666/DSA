class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(), col=matrix[0].size();
        int low=0, high=col-1;
        while(low<row && high>=0) {
            if(matrix[low][high]==target)
                return true;
            if(target>matrix[low][high])
                low++;
            else
                high--;
        }
        return false;

    }
};