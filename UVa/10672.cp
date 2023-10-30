#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int moves;

struct vertex {
	int marbles;
	vector<int> children;
	bool hasParent;
};

int solve(vertex &v, vector<vertex> &verts) {
	if (!v.children.empty()) {
		for (int c : v.children) v.marbles += solve(verts[c], verts);
	}
	int diff = v.marbles - 1;
	if (diff != 0) {
		v.marbles = 1;
		moves += abs(diff);
	}
	return diff;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, j, d; 
	while(cin >> n && n != 0) {
		vector<vertex> verts(n);
		for (int i = 0; i < n; i++) {
			cin >> j;
			cin >> verts[--j].marbles;
			cin >> d;
			verts[j].children = vector<int>(d);
			for(int &idx : verts[j].children) {
				cin >> idx;
				verts[--idx].hasParent = true;
			}
		}

		moves = 0;
		for(vertex v : verts) {
			if (!v.hasParent) solve(v, verts);
		}
		cout << moves << endl;
	}

	return 0;
}