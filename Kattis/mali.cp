#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b, fa[101] = { 0 }, fb[101] = { 0 };
	cin >> n;
	while(n--) {
		cin >> a >> b;
		fa[a]++;
		fb[b]++;
		int ans = 0, ai = 0, sa = fa[0], bi = 100, sb = fb[0];
		while(ai <= 100 && bi > 0) {
			if (!fa[ai]) {
				fa[ai] = sa;
				do
					ai++;
				while(!fa[ai] && ai <= 100);
				if (ai > 100) {
					fb[bi] = sb;
					break;
				}
				sa = fa[ai];
			}
			if(!fb[bi]) {
				fb[bi] = sb;
				do
					bi--;
				while(!fb[bi] && bi > 0);
				if (bi <= 0) {
					fa[ai] = sa;
					break;
				}
				sb = fb[bi];
			}
			ans = max(ans, ai + bi);
			int m = min(fa[ai], fb[bi]);
			fa[ai] -= m;
			fb[bi] -= m;
		}
		cout << ans << endl;
	}

	return 0;
}