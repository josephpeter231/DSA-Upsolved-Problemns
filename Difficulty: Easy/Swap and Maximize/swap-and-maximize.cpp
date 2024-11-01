//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends



class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        long long ans = 0;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<int>vec;
        int i=0,j=n-1;
        while(i<=j){
            vec.push_back(arr[i]);
            vec.push_back(arr[j]);
            i++;j--;
        }
        for(int i=1;i<n;i++){
            ans += abs(vec[i]-vec[i-1]);
            if(i == n-1){
                ans += abs(vec[i]-vec[0]);
            }
        }
        return ans;
    }
};
//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends