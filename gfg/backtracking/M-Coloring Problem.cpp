class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(bool graph[101][101], vector<int>&color, int col, int n, int node) {
        for(int i=0; i<101; i++) {
            if(i!=node && graph[i][node]==1 && color[i]==col )
                return false;
        }
        return true;
    }
    bool graphColoringUtilbool(bool graph[101][101], int m, int n, vector<int>&color, int node) {
        if(node==n) {
            return true;
        }
        for(int i=1; i<=m; i++) {
            if(isSafe(graph, color, i, n, node)) {
                color[node]=i;
                if(graphColoringUtilbool(graph, m,n, color, node+1))
                    return true;
                else
                    color[node]=0;
            }
        }
        return false;
        
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int>color(n,0);
        return graphColoringUtilbool(graph,m,n, color, 0);
    }
};