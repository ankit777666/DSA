class Disjoint {
    public:
        vector<int> size, parent;
        Disjoint(int n) {
            parent.resize(n);
            size.resize(n,1);
            for(int i=0; i<n;i++) {
                parent[i] = i;
            }
            
        }
        int findP(int u) {
            if(u == parent[u])
                return u;
            return parent[u] = findP(parent[u]);
        }
        bool unionBySize(int u, int v) {
            int up = findP(u);
            int vp = findP(v);
            
            if(up != vp) {
                if(size[up]<size[vp])
                    swap(up, vp);
                size[up]+=size[vp];
                parent[vp] = up;
                return true;
            }
            return false;
        }
};
class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    Disjoint d(V);
	    set<pair<int, int>> s;
	    
	    for(int i=0; i<V; i++) {
	        for(int k=0; k<adj[i].size(); k++) {
	            int u=i,v=adj[i][k];
	            if(s.count({u,v}) || s.count({v,u}))
	                continue;
                s.insert({u,v});
                if(!d.unionBySize(u,v))
                    return true;
	        }
	    }
	    return false;
        
	}
};