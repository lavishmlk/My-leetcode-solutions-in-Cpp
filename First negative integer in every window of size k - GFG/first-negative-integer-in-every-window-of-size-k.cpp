// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int N, long long int K) {
         long long window=K; 
         
         deque<long long>q;
         vector<long long>ans;
         
         for(int i=0;i<window;i++){
             
             if(arr[i]<0){
                 q.push_back(arr[i]);
             }
         }
         if(q.empty()==false){
             ans.push_back(q.front());
         }
         else{
             ans.push_back(0);
         }
         
         for(int i=window;i<N;i++){
             if(arr[i]<0){
                 q.push_back(arr[i]);
             }
             if(arr[i-window]<0){
                 q.pop_front();
             }
             if(q.size()>0){
                 ans.push_back(q.front());
             }
             else{
                 ans.push_back(0);
             }
         }
         return ans;
 }