#include<iostream>
#include<vector>
#include<climits>

using namespace std;

#define endl '\n'

vector<int> adj[100005];
int vis[100005] = { 0 }, cid = 0;

void dfs(int i) {
	if (vis[i] > 0)
		return;
	vis[i] = cid;
	for(int j : adj[i])
		dfs(j);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

	int n, m, x[100005], y[100005];
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	while(m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int ans = INT_MAX;
	for(int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cid++;
			dfs(i);
			int minx = INT_MAX, miny = INT_MAX;
			int maxx = INT_MIN, maxy = INT_MIN;
			for(int j = 1; j <= n; j++) {
				if (vis[j] == cid) {
					minx = min(minx, x[j]);
					miny = min(miny, y[j]);
					maxx = max(maxx, x[j]);
					maxy = max(maxy, y[j]);
				}
			}
			int w = maxx - minx, h = maxy - miny;
			int p = (h > 0 ? 2 : 1) * w + (w > 0 ? 2 : 1) * h;
			ans = min(ans, p);
		}
	}
	cout << ans;

	return 0;
}