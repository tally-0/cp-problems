#include<iostream>
#include<numeric>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	while(cin >> n >> m && n + m) {
		int c[20][3];
		for(int i = 0; i < m; i++)
			cin >> c[i][0] >> c[i][1] >> c[i][2];

		int p[8], ans = 0;
		iota(p, p + n, 0);
		do {
			bool f = true;
			for(int i = 0; i < m && f; i++)
				if ((c[i][2] > 0 && abs(p[c[i][0]] - p[c[i][1]]) > c[i][2]) || (c[i][2] < 0 && abs(p[c[i][0]] - p[c[i][1]]) < -c[i][2]))
					f = false;
			if (f)
				ans++;
		} while(next_permutation(p, p + n));

		cout << ans << endl;
	}


	return 0;
}