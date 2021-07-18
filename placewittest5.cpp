
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(x) x.begin(),x.end()
#define MOD 1000000007


void solve(int T)
{
     int n;
     cin>>n;
     if(n<=5){
          cout<<-1<<endl;
          for(int i=1;i<n;i++){
               cout<<i<<" "<<i+1<<endl;
          }
     }
     else{
          cout<<1<<" "<<2<<endl;
          cout<<2<<" "<<3<<endl;
          cout<<2<<" "<<4<<endl;
          for(int i=5;i<=n;i++){
               cout<<3<<" "<<i<<endl;
          }
          for(int i=1;i<n;i++){
               cout<<i<<" "<<i+1<<endl;
          }
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
