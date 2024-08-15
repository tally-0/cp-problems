#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int w, h, n;
	while(cin >> w >> h >> n && w + h + n) {
		int a, b, c, d, mat[500][500] = { 0 };
		for(int i = 0; i < n; i++) {
			cin >> a >> b >> c >> d;
			for(int j = min(a, c) - 1; j < max(a, c); j++)
				for(int k = min(b, d) - 1; k < max(b, d); k++)
					mat[j][k] = true;
		}
		int ans = w * h;
		for(int i = 0; i < w; i++)
			for(int j = 0; j < h; j++)
				ans -= mat[i][j];
		if (ans)
			if (ans == 1)
				cout << "There is one empty spot." << endl;
			else
				cout << "There are " << ans << " empty spots." << endl;
		else
			cout << "There is no empty spots." << endl;
	}

	return 0;
}