class Solution {
public:
	int isEulerCircuit(int V, vector<int>adj[]){
	    // Code here
	    int count = 0;
	    for(int i=0; i<V; i++) {
	        if(adj[i].size() %2 !=0)
	            count++;
	    }
	    if(count == 0)
	        return 2;
        if(count == 2)
            return 1;
        return 0;
	}
};