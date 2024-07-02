class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int startCol=0, endCol=mat[0].size()-1;

        while(startCol<=endCol) {
            int maxRow=0;
            int midCol=startCol+(endCol-startCol)/2;

            for(int row=0; row<mat.size(); row++) {
                maxRow=mat[row][midCol] >=mat[maxRow][midCol] ? row : maxRow;
            }
            bool left = midCol-1 >=startCol && mat[maxRow][midCol-1] > mat[maxRow][midCol];
            bool right = midCol+1<=endCol && mat[maxRow][midCol+1] > mat[maxRow][midCol];

            if(!left && !right) {
                return {maxRow, midCol};
            }
            else if(right)
                startCol=midCol+1;
            else
                endCol=midCol-1;
            
        }
        return {-1,-1};
    }
};