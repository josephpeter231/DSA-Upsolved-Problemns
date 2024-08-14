//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        int sum = 0;
        unordered_map<int,int>up;
        int maxi = 0;
        for(int i=0;i<N;i++){
            sum += A[i];
            if(sum==k) maxi = i+1;
            if(up.find(sum)==up.end()) up[sum] = i;
            if(up.find(sum-k)!=up.end()){
                maxi = max(maxi,i-up[sum-k]);
            }
        }
        
        return maxi;
        // Complete the function
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