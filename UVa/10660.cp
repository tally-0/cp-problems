#include<iostream>
#include<climits>
#include<cstring>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n, grid[25]; 
	cin >> t;
	while(t--) {
		memset(grid, 0, sizeof(grid));
		cin >> n;
		while(n--) {
			int r, c;
			cin >> r >> c;
			cin >> grid[r * 5 + c];
		}
		int bc = INT_MAX, barr[5];
		for(int a = 0; a < 25; a++) {
			for(int b = a + 1; b < 25; b++) {
				for(int c = b + 1; c < 25; c++) {
					for(int d = c + 1; d < 25; d++) {
						for(int e = d + 1; e < 25; e++) {
							int cost = 0;
							for(int f = 0; f < 25; f++) {
								if (!grid[f])
									continue;
								int mc = INT_MAX;
								for(int g : { a, b, c, d, e })
									mc = min(mc, abs(f / 5 - g / 5) + abs(f % 5 - g % 5));
								cost += mc * grid[f];
							}
							if (cost < bc) {
								bc = cost;
								barr[0] = a;
								barr[1] = b;
								barr[2] = c;
								barr[3] = d;
								barr[4] = e;
							}
						}
					}
				}
			}
		}
		cout << barr[0];
		for(int i = 1; i < 5; i++)
			cout << " " << barr[i];
		cout << endl;
	}

	return 0;
}