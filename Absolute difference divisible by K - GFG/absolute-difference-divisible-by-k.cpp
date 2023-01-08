//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    int nc2(int x){
        return (x*(x-1))/2;
    }
  public:
    long long countPairs(int n, int arr[], int k) {
        unordered_map<int,int> m1;
        for(int i=0;i<n;i++){
            int rem=arr[i]%k;
            m1[rem]++;
        }
        int ans=0;
        for(auto it: m1){
            ans+=nc2(it.second);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n;
        
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        cin>>k;

        Solution ob;
        cout << ob.countPairs(n,arr,k) << endl;
    }
    return 0;
}
// } Driver Code Ends