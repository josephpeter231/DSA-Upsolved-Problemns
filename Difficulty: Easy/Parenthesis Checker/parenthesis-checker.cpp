//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    bool ispar(string x){
        stack<char> st;
        
        unordered_map<char,char> mp;
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';
        
        for(int i=0;i<x.size();i++){
            if(x[i] == '(' || x[i] == '{' || x[i] == '['){
                st.push(x[i]);
            }
            else{
                if(st.size() == 0){
                    return false;
                }
                else if(st.top() == mp[x[i]]){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        
        if(st.size() > 0){
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends