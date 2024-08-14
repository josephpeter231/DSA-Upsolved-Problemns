//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        int sum = 0;
        int maxi = 0;
        unordered_map<int,int>up;
        for(int i=0;i<n;i++){
            
            sum += arr[i];
            if(sum==0) maxi = i+1;
            if(up.find(sum)==up.end()) up[sum]=i;
            if(up.find(sum)!=up.end()){
                maxi = max(maxi,i-up[sum]);
            }
        }
        // Your code here
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends