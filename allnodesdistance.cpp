#include<bits/stdc++.h>
#define f(i, n) for(int i = 0; i < n; i++)
#define mle 100100
using namespace std;

typedef long long int ll;

struct Node {
	int val;
	Node *left, *right;

	Node(int val) {
		this -> val = val;
		left = right = nullptr;
	}
};

Node* createTree() {
	int val;
	cin >> val;
	if(val == -1)
		return nullptr;
	Node *node = new Node(val);
	node -> left = createTree();
	node -> right = createTree();
	// update_height(node);
	return node;
}

void level_order(Node *root) {
	queue<Node*> q;

	q.push(root);
	int nodes_in_curr_level = 1, nodes_in_next_level = 0;

	while(!q.empty()) {
		Node *node = q.front();
		q.pop();
		nodes_in_curr_level--;
		cout << node -> val << " ";

		if(node->left) {
			q.push(node -> left);
			nodes_in_next_level++;
		}

		if(node->right) {
			q.push(node -> right);
			nodes_in_next_level++;
		}

		if(nodes_in_curr_level == 0) {
			nodes_in_curr_level = nodes_in_next_level;
			nodes_in_next_level = 0;
			cout << endl;
		}
	}

	cout << endl;
}

unordered_map<int, int> mymap;

void distance(Node* root, int len) {
	if(!root)
		return;
	mymap[root->val] = len;
	distance(root-> left, len+1);
	distance(root -> right, len+1);
}

pair<bool, int> find(Node* root, int val) {
	if(!root)
		return {false, -1};
	if(root -> val == val) {
		distance(root->left, 1);
		distance(root->right, 1);
		mymap[root->val] = 0;
		return {true, 1};
	}
	pair<bool, int> left = find(root-> left, val);
	if(left.first) {
		distance(root -> right, left.second+1);
		mymap[root->val] = left.second;
		return {true, left.second+1};
	}
	pair<bool, int> right = find(root->right, val);
	if(right.first) {
		distance(root -> left, right.second+1);
		mymap[root->val] = right.second;
		return {true, right.second+1};
	}
	return {false, -1};
}

void solve() {
	Node *root = createTree();
	level_order(root);
	find(root, 3);
	for(auto pr: mymap) {
		cout << pr.first << ": " << pr.second << endl;
	}
}

int main(void) {

	#ifndef ONLINE_JUDGE
		freopen("input.in", "r", stdin);
		freopen("outputf.out", "w", stdout);
	#endif

	solve();

	return 0;
}
