#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> ii;
typedef vector<pair<int,int>> vii;
typedef long long ll;

struct state {
	int p; bool u; ll c; 
};

int main() {
	int n, m, u, v, w;
	cin >> n >> m;
	vii adj[n+1];
	for (int f = 0; f < m; f++) {
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}

	ll d[n+1][2];
	for(int i = 0; i <= n; i++) {
		d[i][0] = INT64_MAX;
		d[i][1] = INT64_MAX;
	}
	d[1][0] = 0; d[1][1] = 0;
	auto cmp = [&](const state &a, const state &b) { return a.c > b.c; };
	priority_queue<state, vector<state>, decltype(cmp)> q(cmp);
	q.push({1, false, 0});
	while (!q.empty()) {
		state a = q.top(); q.pop();
		if (d[a.p][a.u] != a.c) continue;
		if (a.p == n) break;
		for (ii b : adj[a.p]) {
			if (!a.u) {
				if (d[a.p][a.u] + b.second / 2 < d[b.first][true]) {
					d[b.first][true] = d[a.p][a.u] + b.second / 2;
					q.push(state{b.first, true, d[b.first][true]});
				}
			}
			if (d[a.p][a.u] + b.second < d[b.first][a.u]) {
				d[b.first][a.u] = d[a.p][a.u] + b.second;
				q.push(state{b.first, a.u, d[b.first][a.u]});
			}
		}
	}
	
	cout << d[n][1];
}