#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

#define endl '\n'

vector<int> adj[205];
int reached, vis[205];

void dfs(int i) {
	if (vis[i])
		return;
	vis[i] = true;
	reached++;
	for(int j : adj[i])
		dfs(j);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

	int n, x[205], y[205], p[205];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i] >> p[i];

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if (i == j)
				continue;
			if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= p[i] * p[i])
				adj[i].push_back(j);
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++) {
		reached = 0;
		memset(vis, false, sizeof(vis));
		dfs(i);
		ans = max(ans, reached);
	}
	cout << ans;

	return 0;
}