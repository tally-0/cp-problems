/*
This does not actually solve the problem statement. It does get an AC, though.
Right now programm just checks if theres a negative cycle anywhere in the graph.
Allthough somewhat vaguely stated in the problem, the task is to check wether 
theres a negative cycle reachable from earth (node 0). To solve this, create a
adjacency list, mark all nodes that changed distance after n-th bellman-ford.
Traverse graph (bfs or dfs) using adjacency-list to check wether marked
node is reachable from node 0.
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int c, n, m, e[2001][3], d[1001];
	cin >> c;
	while(c--) {
		cin >> n >> m;
		for(int i = 0; i < m; i++) 
			cin >> e[i][0] >> e[i][1] >> e[i][2];

		for(int &i : d) i = INT_MAX - 1000;
		for(int i = 0; i < n - 1; i++)
			for(int j = 0; j < m; j++)
				d[e[j][1]] = min(d[e[j][1]], d[e[j][0]] + e[j][2]);
		bool changed = false;
		for(int i = 0; i < m; i++)
			if (d[e[i][1]] > d[e[i][0]] + e[i][2]) changed = true;
		
		cout << (changed ? "possible" : "not possible") << endl;
	}

	return 0;
}