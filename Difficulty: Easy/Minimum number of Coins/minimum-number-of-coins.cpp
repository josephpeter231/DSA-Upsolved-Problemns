//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int n)
    {
        vector<int>v = {1,2,5,10,20,50,100,200,500,2000};
        sort(v.begin(),v.end(),greater<int>());
        vector<int>res;
        // vector
        while(n>0){
            for(int i=0;i<v.size();i++){
                if(n>=v[i]){
                    int x = n/v[i];
                    for(int j=0;j<x;j++){
                        res.push_back(v[i]);
                    }
                    n -= x*v[i];
                    
                    
                    break;
                }
            }
        }
        return res;
    
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