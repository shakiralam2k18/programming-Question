#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007

struct Node{
  int val;
  Node* left, *right;
  Node(int val){
    this->val= val;
    left = right = nullptr;
  }
};

Node * addNode(Node* root, int val){
  if(!root){
    root = new Node(val);
    return root;
  }
  if(root->val > val){
    root->left =addNode(root->left, val);
  }
  if(root->val < val){
    root->right= addNode(root->right, val);
  }
  return root;
}

Node* createBST(vector<int> &arr, int l , int r){
  if(l>r){
    return nullptr;
  }
  int mid= (l+r)>>1;
  Node * root = new Node(arr[mid]);
  root->left = createBST(arr, l,mid-1);
  root->right = createBST(arr,mid+1,r);
  return root;
}

void level_order(Node *root){
  queue<Node*> q;
  q.push(root);
  int nodes_in_current_level=1, nodes_in_next_level=0;
  while(!q.empty()){
    Node * node= q.front();
    q.pop();
    nodes_in_current_level--;
    cout<<node->val<<" ";
    if(node->left){
      q.push(node->left);
      nodes_in_next_level++;
    }
    if(node->right){
      q.push(node->right);
      nodes_in_next_level++;
    }
    if(nodes_in_current_level==0){
      cout<<endl;
      nodes_in_current_level= nodes_in_next_level;
      nodes_in_next_level=0;
    }
  }
}
void solve(int T)
{
  Node * root= nullptr;
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  root= createBST(arr,0,n-1);
  level_order(root);
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
