//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> arr, long long n, long long x) {
        int start = 0;
        int end = n - 1;
        int res = -1; // To track the floor value's index

        while (start <= end) {
            long long mid = start + (end - start) / 2;

            if (arr[mid] <= x) {
                res = mid; // Update result to the current mid
                start = mid + 1; // Move right to find a larger value still <= x
            } else {
                end = mid - 1; // Move left to find a smaller value
            }
        }
        return res; // Return the index of the floor value or -1 if no floor exists
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