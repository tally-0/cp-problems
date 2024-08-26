#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, n, p, q, w[30];
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> n >> p >> q;
		for(int i = 0; i < n; i++)
			cin >> w[i];
		
		sort(w, w + n);
		int ap = 0, aw = 0;
		while(ap <= min(n, p) && aw <= q) {
			aw += w[ap];
			ap++;
		}

		cout << "Case " << t << ": " << ap - 1 << endl;
	}

	return 0;
}