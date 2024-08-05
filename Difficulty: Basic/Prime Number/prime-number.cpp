//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution{
public:
    int isPrime(int N){
        if(N<=1) return false;
        if(N==2) return true;
        
        for(int i=2;i<=sqrt(N);i++){
            if(N%i==0) return false;
        }
        return true;
        // code here
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isPrime(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends