
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(x) x.begin(),x.end()
#define MOD 1000000007
int helper(vector<int>&arr, int i,int k,int n){
     if(k == 0){
          return 0;
     }
     if(i>=n){
          return INT_MAX;
     }
     int ans1 = max(arr[i],helper(arr,i+2,k-1,n));
     int ans2 = helper(arr,i+1,k,n);
     return min(ans1,ans2);
}
void solve(int T)
{
     int n,k;
     cin>>n>>k;
     vector<int> arr(n);
     for(int i=0;i<n;i++){
          cin>>arr[i];
     }
     int mini = *min_element(arr.begin(),arr.end());
     int ans;
     if(mini == arr[0] && k%2 ==1)
          ans = helper(arr,1,k/2,n);
     else if(mini == arr[n-1] && k%2 == 1)
          ans = helper(arr,0,k/2,n-1);
     else
          ans = helper(arr,0,k/2,n);
     cout<<ans<<endl;
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
