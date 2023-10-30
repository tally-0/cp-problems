#include<iostream>
#include<vector>
#include<climits>
#include<map>
#include<queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define ii pair<int,int>

const ii dirs[4] = {
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int p, a, b, dist[2001][2001];
	while(cin >> p && p) {
		memset(dist, 0, sizeof dist);
		map<ii, bool> ends;
		queue<ii> q;
		int maxx = INT_MIN, maxy = INT_MIN, minx = INT_MAX, miny = INT_MAX;
		for(int i = 0; i < p; i++) {
			cin >> a >> b;
			if (a > maxx) maxx = a;
			else if (a < minx) minx = a;
			if (b > maxy) maxy = b;
			else if (b < miny) miny = b;
			q.push({a, b});
			dist[a][b] = 1;
		}
		cin >> p;
		for(int i = 0; i < p; i++) {
			cin >> a >> b;
			if (a > maxx) maxx = a;
			else if (a < minx) minx = a;
			if (b > maxy) maxy = b;
			else if (b < miny) miny = b;
			ends[{a, b}] = true;
		}

		int fd = -1;
		bool brk = false;
		while(!q.empty() && !brk) {
			ii v = q.front(); q.pop();
			for(ii d : dirs) {
				ii u = { v.first + d.first, v.second + d.second };
				if (ends.count(u)) {
					fd = dist[v.first][v.second];
					brk = true;
					break;
				}
				if (u.first > maxx || u.second > maxy || u.first < minx || u.second < miny) continue;
				if (!dist[u.first][u.second]) {
					dist[u.first][u.second] = dist[v.first][v.second] + 1;
					q.push(u);
				}
			}
		}
		cout << fd << endl;
	}
	return 0;
}