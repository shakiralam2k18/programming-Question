
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(x) x.begin(),x.end()
#define MOD 1000000007

void bubbleSort(vector<int>&arr){ // adjacent element....
     int n = arr.size();
     for(int i=0;i<n-1;i++){
          int swapped = 0;
          for(int j=0;j<n-i-1;j++){
               if(arr[j] > arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    swapped = 1;
               }
          }
          if(!swapped){
               break;
          }
     }
}

void solve(int T)
{
     int n;
     cin>>n;
     vector<int> arr(n);
     for(int i=0;i<n;i++){
          cin>>arr[i];
     }
     bubbleSort(arr);
     for(auto i: arr){
          cout<<i<<" ";
     }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("error.out", "w", stderr);
    freopen("outputf.out", "w", stdout);
#endif

    int T = 1;
    //cin >> T;
    for (int t=1;t<=T; t++) {
        solve(t);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
