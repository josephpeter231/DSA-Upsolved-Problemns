//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <vector>
#include <stack>
using namespace std;

class Solution
{
private:
    void dfs(const vector<vector<int>>& adj, vector<int>& vis, int node, stack<int>& st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(adj, vis, it, st);
            }
        }
        st.push(node);  // Push node onto stack after exploring all descendants
    }

    void dfs2(const vector<vector<int>>& adj, vector<int>& vis, int node) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs2(adj, vis, it);
            }
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);
        stack<int> st;

        // First DFS to fill the stack with finishing times
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(adj, vis, i, st);
            }
        }

        // Create the reverse graph
        vector<vector<int>> rev(V);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                rev[it].push_back(i);
            }
        }

        // Reset the visited array for the second DFS
        fill(vis.begin(), vis.end(), 0);

        // Second DFS based on the order in the stack
        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                scc++;
                dfs2(rev, vis, node);
            }
        }

        return scc;
    }
};




//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends