#include<iostream>
#include<vector>
#include<map>
#include<sstream>
#include<algorithm>
#include<queue>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string w, d[200], a, b;
	int n, s, e;
	cin >> n;
	while(n--) {
		int u = 0;
		while(cin >> w && w != "*") d[u++] = w;
		sort(d, d + u, [](string lhs, string rhs) {
			return lhs.length() < rhs.length();
		});
		vector<int> adj[u];
		for(int i = 0; i < u; i++) {
			for(int j = i + 1; d[i].length() == d[j].length() && j < u; j++) {
				int diff = 0;
				for(int k = 0; k < d[i].length(); k++) {
					if (d[i][k] != d[j][k]) diff++;
					if (diff > 1) break;
				}
				if (diff < 2) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
		cin.ignore();
		while(getline(cin, w) && w != "") {
			stringstream ss(w);
			ss >> a >> b;
			for(int i = 0; i < u; i++) {
				if (d[i] == a) s = i;
				if (d[i] == b) e = i;
			}
			int dist[u] = {};
			dist[s] = 0;
			queue<int> q;
			q.push(s);
			while(!q.empty()) {
				int v = q.front(); q.pop();
				for(int ne : adj[v]) {
					if (!dist[ne] && ne != s) {
						dist[ne] = dist[v] + 1;
						q.push(ne);
					}
				}
			}
			cout << a << " " << b << " " << dist[e] << endl;
		}
		if (n) cout << endl;
	}

	return 0;
}