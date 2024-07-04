//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        vector<int> distance(N, INT_MAX);
        vector<vector<int>> adj(N);
        
        // Build the adjacency list
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // Initialize the queue with the source node
        queue<int> q;
        distance[src] = 0;
        q.push(src);

        // BFS traversal
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto it : adj[node]) {
                if (distance[node] + 1 < distance[it]) {
                    distance[it] = distance[node] + 1;
                    q.push(it);
                }
            }
        }
        
        // Replace INT_MAX with -1 to indicate unreachable nodes
        for (int i = 0; i < N; ++i) {
            if (distance[i] == INT_MAX) {
                distance[i] = -1;
            }
        }
        
        return distance;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends