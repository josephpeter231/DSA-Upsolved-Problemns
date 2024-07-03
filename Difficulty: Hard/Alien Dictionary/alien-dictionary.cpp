//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    vector<int> topologicalSort(vector<vector<int> >& adj,
                            int V)
{
    // Vector to store indegree of each vertex
    vector<int> indegree(V);
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }
 
    // Queue to store vertices with indegree 0
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
       
        // Decrease indegree of adjacent vertices as the
        // current node is in topological order
        for (auto it : adj[node]) {
            indegree[it]--;
           
            // If indegree becomes 0, push it to the queue
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return result;
}
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>>adj(K);
        for(int i=0;i<N-1;i++){
            string s = dict[i];
            string s1 = dict[i+1];
            int len = min(s.size(),s1.size());
            for(int i=0;i<len;i++){
                if(s[i]!= s1[i]){
                    adj[s[i]-'a'].push_back(s1[i]-'a');
                    break;
                }
            }
        }
        vector<int>topo = topologicalSort(adj,K);
        string final = "";
        for(auto it:topo){
            final += it+'a';
        }
        return final;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends