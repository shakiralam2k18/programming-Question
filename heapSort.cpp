#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007

int get_leftchild(int parent){
  return 2*parent+1;
}
int get_rightchild(int parent){
  return 2*parent+2;
}
int get_parent(int child){
  return (child-1)/2;
}
void heapify(int parent , int heap[], int n){
  int left_child = get_leftchild(parent), right_child= get_rightchild(parent);
  int max_index = parent;
  if(left_child < n && heap[left_child]> heap[parent])
    max_index = left_child;
  if(right_child < n && heap[right_child] > heap[max_index])
    max_index = right_child;
  if(max_index != parent){
    swap(heap[parent], heap[max_index]);
    //parent = max_index;
    heapify(max_index,heap,n);
  }
}
void create_heap(int heap[], int n){
  for(int i=n/2-1; i>=0; i--){
    heapify(i,heap,n);
  }
}
void pop(int heap[],int &n){
  if(n<=0){
    return;
  }
  int last_index = n-1;
  swap(heap[0],heap[last_index]);
  n = last_index;
  heapify(0,heap,n);
}
void heap_sort(int heap[], int n){
  create_heap(heap,n);
  int temp = n;
	// for(int i = n-1; i>0; i--){
  //   swap(heap[0],heap[i]);
  //   heapify(0,heap,i);
  // }
  for(int i=0;i<temp-1;i++){
    pop(heap,n);
  }

}
void solve(int T)
{
  int n;
  cin>>n;
  int heap[n];
  for(int i=0;i<n;i++){
    cin>> heap[i];
  }
  heap_sort(heap , n);
  for(int i=0;i<n;i++){
    cout<< heap[i]<<" ";
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
