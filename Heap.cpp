#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007

class Maxheap{
  vector<int> heap;

  int get_leftchild(int parent){
    return 2*parent+1;
  }
  int get_rightchild(int parent){
    return 2*parent+2;
  }
  int get_parent(int child){
    return (child-1)/2;
  }
  void heapify(int parent){
    int left_child = get_leftchild(parent), right_child= get_rightchild(parent);
    int max_index = parent;
    if(left_child < heap.size() && heap[left_child]> heap[parent])
      max_index = left_child;
    if(right_child < heap.size() && heap[right_child] > heap[max_index])
      max_index = right_child;
    if(max_index != parent){
      swap(heap[parent], heap[max_index]);
      parent = max_index;
      heapify(parent);
    }
  }
public:
  Maxheap(){
    heap.clear();
  }
  bool empty(){
    return heap.size()==0;
  }
  int top(){
    if(heap.empty() == 0){
      return -1;
    }
    return heap[0];
  }
  void push(int val){
    if(empty()){
      heap.push_back(val);
      return;
    }
    heap.push_back(val);
    int child = heap.size()-1;
    int parent = get_parent(child);
    while(child>0 && heap[child] > heap[parent]){
      swap(heap[child], heap[parent]);
      child = parent;
      parent = get_parent(child);
    }
  }
  void pop(){
    if(empty()){
      return;
    }
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    heapify(0);
  }
};

void solve(int T)
{
  int n;
  cin>>n;
  Maxheap arr;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    arr.push(x);
  }
  while(!arr.empty()){
    cout<<arr.top()<<" ";
    arr.pop();
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
