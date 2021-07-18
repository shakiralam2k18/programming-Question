#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007

int construct_segment_tree(int segment_tree[], int index, int l,int r,int arr[]){
  if(l==r){
    return segment_tree[index]=arr[l];
  }
  int mid=(l+r)/2;
  return segment_tree[index]=max(construct_segment_tree(segment_tree,2*index+1,l,mid,arr),
            construct_segment_tree(segment_tree,2*index+2,mid+1,r,arr));
}
int query(int segment_tree[], int index, int l, int r,int ql, int qr){
  if(l>qr || r<ql){
    return INT_MIN;
  }
  if(ql<=l && qr>=r){
    return segment_tree[index];
  }
  int mid= (l+r)>>1;
  return max(query(segment_tree,2*index+1,l,mid,ql,qr),
            query(segment_tree,2*index+2,mid+1,r,ql,qr));
}

void update(int segment_tree[],int seg_index,int l, int r,int index,int val,int arr[]){
  if(l==r){
    segment_tree[seg_index] = arr[index] = val;
    return;
  }
  int mid = (l+r)/2;
  if(index <= mid)
      update(segment_tree,2*seg_index+1,l,mid,index,val,arr);
  else
      update(segment_tree,2*seg_index+2,mid+1,r,index,val,arr);
  segment_tree[seg_index] = max(segment_tree[2*seg_index+1], segment_tree[2*seg_index+2]);

}

void level_order(int segment_tree[], int root, int sz){
  queue<int> q;
  q.push(root);
  int nodes_in_current_level=1, nodes_in_next_level=0;

  while(!q.empty()){
    int node=q.front();
    q.pop();
    nodes_in_current_level--;
    int left_child= 2*node+1, right_child=2*node+2;
    cout<<segment_tree[node]<<" ";
    if(left_child<sz && segment_tree[left_child]!=INT_MIN){
      q.push(left_child);
      nodes_in_next_level++;
    }
    if(right_child<sz && segment_tree[right_child]!=INT_MIN){
      q.push(right_child);
      nodes_in_next_level++;
    }
    if(nodes_in_current_level==0){
      nodes_in_current_level = nodes_in_next_level;
      nodes_in_next_level=0;
      cout<<endl;
    }
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
  int segment_tree[4*n];
  fill(segment_tree,segment_tree+4*n,INT_MIN);
  construct_segment_tree(segment_tree,0,0,n-1,arr);
  //int ans= query(segment_tree,0,0,n-1,1,5);
  //cout<<ans<<endl;
  level_order(segment_tree,0,4*n);
  // for(int i=0;i<4*n;i++){
  //   cout<<segment_tree[i]<<endl;
  // }
  update(segment_tree,0,0,n-1,2,7,arr);
  level_order(segment_tree,0,4*n);
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
