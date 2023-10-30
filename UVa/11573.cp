#include<iostream>
#include<vector>
#include<deque>

using namespace std;

#define endl '\n'

const int dirs[8][2] = {
	{-1, 0},
	{-1, 1},
	{0, 1},
	{1, 1},
	{1, 0},
	{1, -1},
	{0, -1},
	{-1, -1}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r, c, n, sx, sy, ex, ey;
	string s;
	cin >> r >> c;
	int flow[r*c];
	for(int i = 0; i < r; i++) {
		cin >> s;
		for(int j = 0; j < c; j++) flow[i*c+j] = s[j] - '0';
	}
	cin >> n;
	while(n--) {
		cin >> sx >> sy >> ex >> ey;
		sx--; sy--; ex--; ey--;
		int dist[r*c];
		for(int i = 0; i < r*c; i++) dist[i] = 2000;
		dist[sx*c+sy] = 0;
		deque<int> q;
		q.push_back(sx*c+sy);
		while(!q.empty()) {
			int v = q.front(); q.pop_front();
			if (v == ex*c+ey) break;
			for(int i = 0; i < 8; i++) {
				if (!(v % c) && dirs[i][1] < 0) continue;
				if (!((v+1) % c) && dirs[i][1] > 0) continue;
				int u = v + dirs[i][0]*c + dirs[i][1];
				if(u >= r*c || u < 0) continue;
				int cost = flow[v] != i;
				if(dist[u] > dist[v] + cost) {
					dist[u] = dist[v] + cost;
					if (cost) q.push_back(u);
					else q.push_front(u);
				}
			}
		}
		cout << dist[ex*c+ey] << endl;
	}

	return 0;
}