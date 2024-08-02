//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
#include <vector>
#include <algorithm>

class Solution {
public:
    void sortIt(std::vector<ll>& arr) {
        std::vector<ll> odd;
        std::vector<ll> even;
        for(auto it : arr) {
            if(it % 2 == 0) {
                even.push_back(it);
            } else {
                odd.push_back(it);
            }
        }
        std::sort(odd.begin(), odd.end(), std::greater<ll>());
        std::sort(even.begin(), even.end());

        ll idx = 0;
        for(ll i = 0; i < odd.size(); i++) {
            arr[idx++] = odd[i];
        }

        for(ll i = 0; i < even.size(); i++) {
            arr[idx++] = even[i];
        }
    }
};


//{ Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<long long> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        long long number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        ob.sortIt(arr);

        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends