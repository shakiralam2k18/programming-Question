#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007

struct Node{
  int val;
  Node* left;
  Node *right;
  Node(int val){
    this->val=val;
    left=right= nullptr;
  }
};
void print(Node *root){
  if(!root){
    return;
  }
  cout<<root->val<<" ";
  print(root->left);

  print(root->right);

}
Node* createTree(int val){
  if(val==-1){
    return nullptr;
  }
  Node * root= new Node(val);
  int temp;
  cin>>temp;
  root->left=createTree(temp);
  cin>>temp;
  root->right=createTree(temp);
  return root;
}
void level_order(Node * root){
  queue<Node*> q;
  q.push(root);
  q.push(nullptr);
  while(!q.empty()){
    Node* node= q.front();
    q.pop();
    if(!node){
      if(q.empty())
        break;
      cout<<endl;
      q.push(nullptr);
      continue;
    }
    cout<<node->val<<" ";
    if(node->left){
      q.push(node->left);
    }
    if(node->right){
      q.push(node->right);
    }
  }
}

void solve(int T)
{
  int n;
  cin>>n;
  Node *root=createTree(n);
  print(root);
  cout<<endl;
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
