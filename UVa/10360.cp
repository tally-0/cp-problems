#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, d, n;
	cin >> t;
	while(t--) {
		cin >> d >> n;
		int killed[1025][1025] = { 0 };
		for(int x, y, k; n; n--) {
			cin >> x >> y >> k;
			for(int i = max(0, y - d); i <= min(y + d, 1024); i++)
				for(int j = max(0, x - d); j <= min(x + d, 1024); j++)
					killed[i][j] += k;
		}

		int ansx, ansy, ansk = -1;
		for(int x = 0; x < 1025; x++) {
			for(int y = 0; y < 1025; y++) {
				if (killed[y][x] > ansk) {
					ansk = killed[y][x];
					ansx = x;
					ansy = y;
				}
			}
		}

		cout << ansx << " " << ansy << " " << ansk << endl;
	}

	return 0;
}