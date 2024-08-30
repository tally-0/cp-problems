#include <iostream>
#include <cmath>

using namespace std;

#define endl '\n'

void rec(int l, int r, int h) {
	if (h == 0 || l > r)
		return;
	int m = max(r - (1 << (h - 1)) + 1, l);
	cout << " " << m;
	rec(l, m - 1, h - 1);
	rec(m + 1, r, h - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	int n, h;
	while (cin >> n >> h && n + h) {
		cout << "Case " << t++ << ":";

		if ((1 << h) - 1 < n) {
			cout << " Impossible." << endl;
			continue;
		}
		h = min(h, n);
		rec(1, n, h);

		cout << endl;
	}
}