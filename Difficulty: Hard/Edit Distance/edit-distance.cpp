//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    
    vector<vector<int>>dp;
    
    int solve(string str1,string str2,int n,int m,int i,int j){
if(i==n){
    
    return m-j;
}

if(j==m){
    return n-i;
}
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(str1[i]==str2[j]){
            return dp[i][j]=solve(str1,str2,n,m,i+1,j+1);
        }
        
        return dp[i][j]=1+min((solve(str1,str2,n,m,i,j+1)),min(solve(str1,str2,n,m,i+1,j),solve(str1,str2,n,m,i+1,j+1)));
    }
  public:
    int editDistance(string str1, string str2) {
    
    
    int n=str1.size();
    int m=str2.size();
    
    dp.resize(n+1,vector<int>(m+1,-1));
    return solve(str1,str2,n,m,0,0);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends