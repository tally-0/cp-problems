#include<iostream>
#include<vector>
#include<climits>
#include<cstring>

using namespace std;

#define endl '\n'
typedef long long ll;
typedef pair<int,int> ii;

constexpr ll BIG = LLONG_MAX;
vector<int> revadj[2501];
bool changed[2501], vis[2501];

void dfs(int u, bool &valid) {
	if (vis[u]) return;
	vis[u] = true;
	if (changed[u]) {
		valid = false;
		return;
	}
	for(int ne : revadj[u]) dfs(ne, valid);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, u, v, w;
	cin >> n >> m;
	int edges[m][3];
	for(auto &e : edges) {
		cin >> e[0] >> e[1] >> e[2];
		revadj[e[1]].push_back(e[0]);
	}

	ll d[n+1];
	for(auto &i : d) i = BIG;
	d[1] = 0;
	for(int i = 0; i < n - 1; i++)
		for(auto e : edges)
			if (d[e[0]] != BIG)
				d[e[1]] = min(d[e[1]], d[e[0]] + e[2]);
	memset(changed, false, sizeof(changed));
	for(auto e : edges)
		if (d[e[0]] != BIG)
			if(d[e[1]] > d[e[0]] + e[2]) changed[e[1]] = true;
	memset(vis, false, sizeof(vis));
	bool valid = true;
	dfs(n, valid);

	if (valid) cout << d[n];
	else cout << -1;
	cout << endl;

	return 0;
}