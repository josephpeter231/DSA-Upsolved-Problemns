//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        string s;
        if(arr[0][0]!=arr[n-1][0]) return "-1";
        for(int i=0;i<arr[0].length();i++){
            if(arr[0][i]!=arr[n-1][i]){
                break;
            }
            s+=arr[0][i];
        }
        return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends