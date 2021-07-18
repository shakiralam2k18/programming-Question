
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define watch(x) cout << (#x) << " is " << (x) << endl
#define printVec(vec) {for(auto &x : vec) cout << x <<" "; cout << endl; }
#define printMap(mp) {for(auto &p : mp) cout << p.first <<" " <<p.second <<endl;}
#define hM 9999999900000001
#define inf 1e17

// ******l-r frequency nikalna hai to 26*n ka array bana0******

void solve(int T)
{
       int n , m;
       cin >> n >> m;
       __gcd(1,2);
       __gcd(1,2);
         __gcd(1,2);
           __gcd(1,2);
            __gcd(1,2);
       cout<<"Case #"<<T<<": ";
       set<int> myset;
       for(int i = 0 ; i < n ; i++){
         int x, y;
         cin >> x>> y;
         for(int j = x; j <= y;j++){
           myset.insert(j);
         }
       }
         __gcd(1,2);
           __gcd(1,2);
             __gcd(1,2);
               __gcd(1,2);
       for(int i = 0 ; i < m ; i++){
         int talent;
         cin >> talent;
         auto it = myset.lower_bound(talent);
         set<int> :: iterator zayan;
         int diff = INT_MAX;
         if(it != myset.end()){
           diff = *it - talent;
           zayan = it;
         }
         __gcd(1,2);
           __gcd(1,2);
             __gcd(1,2);
               __gcd(1,2);
         if(it != myset.begin()){
           it--;
           int d = abs(talent - *it);
           if(d  <= diff){
             zayan = it;
           }
         }
         cout << *zayan <<" ";
         myset.erase(zayan);
       }
       cout <<endl;
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
    cin >> T;
    for (int t=1;t<=T; t++) {
        solve(t);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
