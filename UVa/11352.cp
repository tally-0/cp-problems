#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include <cstring>

using namespace std;

#define endl '\n'
#define ii pair<int,int>

const int dirs[8][2] = {
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0},
	{-1, 1},
	{1, 1},
	{-1, -1},
	{1, -1}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, m, n;
	ii st, e;
	string s;
	cin >> t;
	while(t--) {
		cin >> m >> n;
		bool g[m][n];
		memset(g, true, sizeof(g));
		for(int i = 0; i < m; i++) {
			cin >> s;
			for(int j = 0; j < n; j++) {
				if (s[j] == 'Z') {
					g[i][j] = false;
					if (i + 1 < m) {
						if (j + 2 < n) g[i+1][j+2] = false;
						if (j - 2 >= 0) g[i+1][j-2] = false;
						if (i + 2 < m) {
							if (j + 1 < n) g[i+2][j+1] = false;
							if (j - 1 >= 0) g[i+2][j-1] = false;
						}
					}
					if (i - 1 >= 0) {
						if (j + 2 < n) g[i-1][j+2] = false;
						if (j - 2 >= 0) g[i-1][j-2] = false;
						if (i - 2 >= 0) {
							if (j + 1 < n) g[i-2][j+1] = false;
							if (j - 1 >= 0) g[i-2][j-1] = false;
						}
					}
				} else if (s[j] == 'A') st = {i, j};
				else if (s[j] == 'B') e = {i, j};
			}
		}
		g[st.first][st.second] = true;
		g[e.first][e.second] = true;
		map<ii, int> dist;
		dist[st] = 0;
		queue<ii> q;
		q.push(st);
		while(!q.empty() && !dist.count(e)) {
			ii v = q.front(); q.pop();
			for(auto d : dirs) {
				ii u = {v.first + d[0], v.second + d[1]};
				if(u.first < m && u.first >= 0 && u.second >= 0 && u.second < n && !dist.count(u) && g[u.first][u.second]) {
					dist[u] = dist[v] + 1;
					q.push(u);
				}
			}
		}
		if(dist.count(e)) cout << "Minimal possible length of a trip is " << dist[e] << endl;
		else cout << "King Peter, you can't go now!" << endl;
	}

	return 0;
}