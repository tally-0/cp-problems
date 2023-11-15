#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	vector<int> adj[100001];
	cin >> n;
	for(int i = 0, u, v; i < n; i++) {
		cin >> u >> v; 
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int col[100001];
	long long cnt[2] = { 0 };
	memset(col, -1, sizeof(col));
	queue<int> q;
	q.push(1);
	col[1] = 0;
	cnt[0] = 1;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int v : adj[u]) {
			if (col[v] == -1) {
				col[v] = 1 - col[u];
				cnt[col[v]]++;
				q.push(v);
			}
		}
	}

	cout << cnt[0] * cnt[1] - n + 1 << endl;

	return 0;
}