#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007

struct segmentTree{
  int* tree,*lazy,n;

  segmentTree(vector<int>& arr){
    n = arr.size();
    int tree[4*n];
    int lazy[4*n];
    fill(tree,tree+4*n,0);
    fill(lazy,lazy+4*n,0);
  }

  void build(vector<int>& arr, int s, int e,int root){
    if(s == e){
      return tree[root] = arr[s];
    }
    int mid =(s+e)/2;
    return tree[root] = max(build(arr,s,mid,2*root+1),build(arr,mid+1,e,2*root+2));
  }

  int query_helper(int root,int s, int e, int qs, int qe){
    if(qs>qe){
      return INT_MIN;
    }
    if(qs==s && qe==e){
      return tree[root];
    }
    int mid = (s+e)/2;
    return max(query_helper(2*root+1,s,mid,qs,min(mid,qe)),query_helper(2*root+2,mid+1,e,max(mid+1,qs),e));
  }

  void update_helper(int root,int s,int e,int us, int ue, int addend){
    if(us>ue){
      return;
    }
    if(us== s && ue==e){
      tree[root]+= addend;
      lazy[root]+= addend;
    }
  }
};


void solve(int T)
{

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
