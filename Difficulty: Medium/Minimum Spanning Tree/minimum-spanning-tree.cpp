//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution
{
	public:
    // Function to find the sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Min-heap priority queue to store (weight, node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        // Start with node 0 and weight 0
        pq.push({0, 0});
        
        // Visited array to keep track of nodes that are included in the MST
        vector<int> vis(V, 0);
        
        int sum = 0;
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int node = it.second;
            int weight = it.first;
            
            // If the node is already visited, skip it
            if (vis[node] == 1) continue;
            
            // Mark the node as visited
            vis[node] = 1;
            
            // Add the edge's weight to the sum
            sum += weight;
            
            // Iterate over the adjacent nodes
            for (auto &edge : adj[node]) {
                int adjNode = edge[0];
                int adjWeight = edge[1];
                
                // If the adjacent node is not visited, push it into the priority queue
                if (!vis[adjNode]) {
                    pq.push({adjWeight, adjNode});
                }
            }
        }
        
        return sum;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends