//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <unordered_map>

class Solution {
public:
    int lenOfLongSubarr(int A[], int N, int K) {
        std::unordered_map<long long, int> sumMap;
        long long sum = 0;
        int maxlen = 0;

        for (int i = 0; i < N; ++i) {
            sum += A[i];

            // If sum is equal to K, update maxlen
            if (sum == K) {
                maxlen = i + 1;
            }

            // If (sum - K) exists in the map, we found a subarray
            if (sumMap.find(sum - K) != sumMap.end()) {
                maxlen = std::max(maxlen, i - sumMap[sum - K]);
            }

            // Only add the current sum to the map if it doesn't exist
            if (sumMap.find(sum) == sumMap.end()) {
                sumMap[sum] = i;
            }
        }

        return maxlen;
    }
};


//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends