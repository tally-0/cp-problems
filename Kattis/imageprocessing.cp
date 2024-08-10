#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, w, n, m, img[21][21], ker[21][21];
	cin >> h >> w >> n >> m;
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
			cin >> img[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> ker[n - i][m - j];
	for(int i = 0; i <= h - n; i++) {
		for(int j = 0; j <= w - m; j++) {
			int s = 0;
			for(int g = 0; g < n; g++)
				for(int f = 0; f < m; f++)
					s += ker[g][f] * img[i + g][j + f];
			cout << s << " ";
		}
		cout << endl;
	}

	return 0;
}