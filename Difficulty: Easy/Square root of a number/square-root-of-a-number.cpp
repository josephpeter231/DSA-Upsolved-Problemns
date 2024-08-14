//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
#define ll long long int
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        if (n<=1) return n;
        
        ll left = 0;
        ll right = n;
        while(left<=right){
            ll mid = (left+right)/2;
            ll test = mid*mid;
            if(test==n) return mid;
            else if(test>n) right = mid-1;
            else left = mid+1;
        }
        return right;
        // Your code goes here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends