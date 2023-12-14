class Solution{
public:	
	
	void rotateMatrix(vector<vector<int>>& arr, int n) {
	    // code here   
	    for(int i = 0;i< n; i++) {
           for(int j = i+1; j<n ; j++) {
               swap(arr[i][j] , arr[j][i]);
           }
        }
        reverse(begin(arr), end(arr));
	}

};