//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Your code here
        // Tabulation solution
        vector<int> dp(n + 1, 0);
        // return max(0, fun(n, x, y, z, dp));
        dp[0] = 0;
        for(int rem_len = 1; rem_len <= n; rem_len++) {
            int opt1 = (rem_len - x > -1) ? 1 + dp[rem_len - x] : -1e9;
            int opt2 = (rem_len - y > -1) ? 1 + dp[rem_len - y] : -1e9;
            int opt3 = (rem_len - z > -1) ? 1 + dp[rem_len - z] : -1e9;
            dp[rem_len] = max({opt1, opt2, opt3});
        }
        return max(dp[n], 0);
        
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends