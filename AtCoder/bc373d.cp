#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'
typedef ll long long;

vector<pair<int,int>> g[200001];
ll x[200001];
bool v[200001] = { false };

void dfs(int i) {
	if (v[i])
		return;
	v[i] = true;
	for(const auto& ne : g[i]) {
		if (v[ne.first])
			continue;
		x[ne.first] = x[i] - ne.second;
		dfs(ne.first);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for(int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, -w});
	}

	for(int i = 1; i <= n; i++) {
		if (!v[i]) {
			x[i] = 0;
			dfs(i);
		}
		cout << x[i] << " ";
	}

	return 0;
}