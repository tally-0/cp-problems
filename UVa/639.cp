#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, b[4][4];
	while(cin >> n && n) {
		char a;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> a;
				b[i][j] = (a == 'X');
			}
		}

		int ans = 0;
		for(int s = 0; s < (1 << n * n); s++) {
			bool v = true;
			for(int i = 0; i < n && v; i++) {
				bool f1 = true;
				bool f2 = true;
				for(int j = 0; j < n && v; j++) {
					if (b[j][i])
						if (s & (1 << j * n + i))
							v = false;
						else
							f1 = true;	
					else if (s & (1 << j * n + i))
						if (!f1)
							v = false;
						else
							f1 = false;
					if (b[i][j])
						if (s & (1 << i * n + j))
							v = false;
						else
							f2 = true;
					else if (s & (1 << i * n + j))
						if (!f2)
							v = false;
						else
							f2 = false;
				}
			}
			if (v)
				ans = max(ans, __builtin_popcount(s));
		}
		
		cout << ans << endl;
	}

	return 0;
}