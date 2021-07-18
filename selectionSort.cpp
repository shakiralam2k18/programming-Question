
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(x) x.begin(),x.end()
#define MOD 1000000007

void selectionSort(vector<int>& arr){
     int n = arr.size();
     for(int i=0;i<n;i++){
          int mini = arr[i];
          int idx = i;
          for(int j=i+1;j<n;j++){
               if(mini > arr[j]){
                    mini = arr[j];
                    idx = j;
               }
          }
          swap(arr[i],arr[idx]);
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
     selectionSort(arr);
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
