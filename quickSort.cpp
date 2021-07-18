
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(x) x.begin(),x.end()
#define MOD 1000000007

int partition_index(int arr[], int beg, int end, int pivot){
    int s=beg, e=end;
    while(s<e){
        while(arr[s]<pivot && s<=end){
            s++;
        }
        while(arr[e]>pivot && e>=beg){
            e--;
        }
        if(s<e){
            swap(arr[s],arr[e]);
        }
    }
    return e;
}

void quickSort(int arr[], int l, int r){
     if(l<r){
          int random=l+rand()%(r-l+1);
          int pivot=arr[random];
          int idx = partition_index(arr,l,r,pivot);
          quickSort(arr,l,idx-1);
          quickSort(arr,idx+1,r);
     }
}

void solve(int T)
{
     int n;
     cin>>n;
     int arr[n];
     for(int i=0;i<n;i++){
          cin>>arr[i];
     }
     quickSort(arr,0,n-1);
     for(auto &i: arr){
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
