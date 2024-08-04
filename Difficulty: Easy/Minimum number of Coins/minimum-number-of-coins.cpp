//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int>res;
        vector<int>v = {2000,500,200,100,50,20,10,5,2,1};
        for(auto it:v){
            if(N>=it){
                int x = N/it;
                for(int j =0;j<x;j++){
                    res.push_back(it);
                }
                N-=x*it;
                
            }
        }
        return res;
        // code here
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends