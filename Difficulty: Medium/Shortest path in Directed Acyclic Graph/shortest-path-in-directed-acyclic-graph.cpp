//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
    void dfs(vector<vector<pair<int,int>>>&adj,vector<int>&vis,stack<int>&st,int node){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it.first]){
                dfs(adj,vis,st,it.first);
            }
        }
        st.push(node);
        
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         vector<vector<pair<int,int>>>adj(N);
         for(auto it:edges){
             int u = it[0];
             int v = it[1];
             int w = it[2];
             adj[u].push_back({v,w});
         }
         stack<int>st;
         vector<int>vis(N,0);
         for(int i=0;i<N;i++){
            if(!vis[i]){
                dfs(adj,vis,st,i);
                
            }
         }
        //  vector<int>topo;
        //  while(!st.empty()){
        //      topo.push_back(st.top());
        //      st.pop();
        //  }
        //  return topo;
        int src = 0;
        vector<int>distance(N,INT_MAX);
        distance[src]=0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(distance[node]!=INT_MAX){
                for(auto it:adj[node]){
                    if(distance[node]+it.second<distance[it.first]){
                        distance[it.first] = distance[node]+it.second;
                    }
                }
            }
            
        }
        for(int i=0;i<distance.size();i++){
            if(distance[i]==INT_MAX){
                distance[i]=-1;
            }
        }
        return distance;
        
        // code here
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends