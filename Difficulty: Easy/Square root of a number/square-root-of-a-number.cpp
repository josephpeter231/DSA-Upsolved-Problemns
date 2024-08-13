//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        long long int left = 0;
        long long int right = n;
        if(n<=1){
            return n;
            
        }
        while(left<=right){
            long long int mid = (left+right)/2;
            long long int test = mid*mid;
            if(test==n){
                return mid;
            }
            else if(test>n){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return right;
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