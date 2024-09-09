#include<iostream>

using namespace std;

#define endl '\n'

int s, d, r[12], ans;

void backtrack(int i, int sum) {
	if (i == 12) {
		ans = max(ans, sum);
		return;
	}
	if (i > 3) {
		int c = 0;
		for(int j = i - 4; i < i; i++)
			c += r[j];
		if (c + s < 0) {
			r[i] = s;
			backtrack(i + 1, sum + s);
		}
		if (c - d < 0) {
			r[i] = -d;
			backtrack(i + 1, sum - d);
		}
	} else {
		r[i] = s;
		backtrack(i + 1, sum + s);
		r[i] = -d;
		backtrack(i + 1, sum - d);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> s >> d) {
		ans = -1;
		backtrack(0, 0);
		if (ans >= 0)
			cout << ans << endl;
		else
			cout << "Deficit" << endl;
	}

	return 0;
}