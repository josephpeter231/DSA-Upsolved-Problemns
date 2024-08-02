#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        unordered_map<int, int> up;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            up[v[i]]++;
        }
        
        auto comp = [&up](int a, int b) {
            if (up[a] == up[b]) {
                return a < b; 
            }
            return up[a] > up[b]; 
        };
        
        sort(v.begin(), v.end(), comp);
        
        for (auto it : v) {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
