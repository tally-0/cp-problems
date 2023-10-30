#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, s[19], e[19];
	cin >> n;
	while(n--) {
		int m, a, b;
		for(m = 0; cin >> a >> b && a + b; m++) {
			s[m] = a;
			e[m] = b;
		}
		int maxne = 0;
		for(int i = 0; i < (1 << m); i++) {
			int ne = 0, used[10] = { false }, f = true;
			for(int j = 0; j < m; j++) {
				if (i & (1 << j)) {
					for(int k = s[j]; k < e[j]; k++) {
						if (used[k]) {
							f = false;
							break;
						}
						used[k] = true;
					}
					if (!f)
						break;
					ne++;
				}
			}
			if (f)
				maxne = max(maxne, ne);
		}

		cout << maxne << endl;
	}
		
	return 0;
}