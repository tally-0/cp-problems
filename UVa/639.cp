#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, grid[4][4];
	string s;
	while(cin >> n && n) {
		for(int i = 0; i < n; i++) {
			cin >> s;
			for(int j = 0; j < n; j++)
				grid[i][j] = s[j] == '.' ? true : false;
		}

		int maxrp = 0;
		for(int a = 0; a < (1 << (n * n)); a++) {
			int f = true, rp = 0, csee[4] = { false };
			for(int i = 0; i < n; i++) {
				bool rsee = false;
				for(int j = 0; j < n; j++) {
					if (a & (1 << (i * n + j))) {
						if (rsee || !grid[i][j] || csee[j]) {
							f = false;
							break;
						}
						rp++;
						rsee = true;
						csee[j] = true;
					}
					if (!grid[i][j]) {
						rsee = false;
						csee[j] = false;
					}
				}
				if (!f)
					break;
			}
			if (f && rp > maxrp)
				maxrp = rp;
		}
		
		cout << maxrp << endl;
	}

	return 0;
}