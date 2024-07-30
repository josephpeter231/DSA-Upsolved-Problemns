//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int maxi = INT_MIN;
    int findFloor(vector<long long> &v, long long n, long long x) {
        for(int i=0;i<v.size();i++){
            if(v[i]<=x) maxi = max(maxi,i);
        }
        return maxi==INT_MIN?-1:maxi;
        // Your code here
    }
};


//{ Driver Code Starts.

int main() {

    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long x;
        cin >> x;

        vector<long long> v;

        for (long long i = 0; i < n; i++) {
            long long temp;
            cin >> temp;
            v.push_back(temp);
        }
        Solution obj;
        cout << obj.findFloor(v, n, x) << endl;
    }

    return 0;
}
// } Driver Code Ends