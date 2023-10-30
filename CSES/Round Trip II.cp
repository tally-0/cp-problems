#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define endl '\n'

vector<int> adj[10001];
int s, e, p[10001], vis[10001];

void dfs(int u) {
	vis[u] = 1;
	for(int v : adj[u]) {
		if (vis[v] == 0) {
			p[v] = u;
			dfs(v);
			if (s) return;
		} else if(vis[v] == 1) {
			e = u;
			s = v;
			return;
		}
	}
	vis[u] = 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, a, b;
	cin >> n >> m;
	while(m--) {
		cin >> a >> b;
		adj[a].push_back(b);
	}

	for(int i = 1; i <= n && !s; i++)
		if (vis[i] == 0)
			dfs(i);
	if (!s) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	vector<int> ans;
	ans.push_back(s);
	for(int u = e; u != s; u = p[u])
		ans.push_back(u);
	ans.push_back(s);
	reverse(ans.begin(), ans.end());

	cout << ans.size() << endl;
	for(int u : ans)
		cout << u << " ";

	return 0;
}