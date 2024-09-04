#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int n[5];

bool bt(int s, int i) {
	if (i == 5)
		return s == 23;
	return bt(s + n[i], i + 1) || bt(s - n[i], i + 1) || bt(s * n[i], i + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n[0] >> n[1] >> n[2] >> n[3] >> n[4] && n[0] + n[1] + n[2] + n[3] + n[4]) {
		sort(n, n + 5);

		bool ans = false;
		do {
			ans = bt(n[0], 1);
		} while(next_permutation(n, n + 5) && !ans);

		cout << (ans ? "Possible" : "Impossible") << endl;
	}

	return 0;
}